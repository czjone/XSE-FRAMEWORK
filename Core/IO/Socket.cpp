#include <XSE/Core/Socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <thread>
#include <sys/ioctl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>


XSE_NS_EXT_USING(CORE_NS_NAME);
using namespace network;

#define head  4  //data package head len
#define buflen 1024 // recive buffer len
#define readSpan 15 //read span (MS)

//-------------------------------
static int sigleCode = 0;
void sigleHandler(int code){
    sigleCode = code;
}

//-------------------------------

socket::event::~event(){}

void socket::event::setData(unsigned char* bytes,unsigned int len ){
    this->m_bytes =  bytes;
    this->m_len = len;
}

//---------------------------------
void socket::reciveEvent::invork(args&){
    
}

//socket::event::eventType socket::reciveEvent::getEventType(){
//    return socket::event::eventType::RECIVE;
//}

//--------------------------------

socket::onNetworkError::onNetworkError(){
    
}

socket::onNetworkError::onNetworkError(networkErrorNo erro){
    this->setData((unsigned char*)&erro, sizeof(erro));
}

void socket::onNetworkError::invork(args&){
    data dt;
    dt.len = this->m_len;
    dt.data = this->m_bytes;
};

//socket::event::eventType socket::onNetworkError::getEventType(){
//    return socket::event::eventType::NETWORK_ERROR;
//}

//-----------------------------------
socket::socket(unsigned char* ip,unsigned int port){
    new (this)socket(ip,port,socketType::TCP);
}
socket::socket(unsigned char* ip,unsigned int port,socketType type):m_ip(nullptr),port(-1){
    size_t len =strlen((const char*)ip);
    m_ip =  new unsigned char[len];
    memccpy(m_ip, ip, 1, len);
    this->port = port;
    this->m_socketType = type;
}

socket::~socket(){
    delete [] this->m_ip;
}

void socket::connect(){
    
    struct sockaddr_in server_addr;
    
    //remote server address
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(this->port);
    if( inet_pton(AF_INET, (const char*)this->m_ip, &server_addr.sin_addr) < 0){    //set ip address
//        this->dispatchNetworkError(onNetworkError::networkErrorNo::LOCAL_NETWORK_PORT_ERROR);
        args arg(nullptr);
        this->dispatch(onNetworkError::networkErrorNo::LOCAL_NETWORK_PORT_ERROR, arg);
        return;
    }
    
    this->socketfd = ::socket(AF_INET, SOCK_STREAM, 0);    //ipv4,TCP数据连接
    ioctl(this->socketfd, FIONBIO,1);
    int connfd = ::connect(this->socketfd, (struct sockaddr*)&server_addr, sizeof(server_addr)); //连接到服务器
    
    if (connfd!=0) {
//        this->dispatchNetworkError(onNetworkError::networkErrorNo::REMOTE_NOT_ACTIVED);
        args arg(nullptr);
        this->dispatch(onNetworkError::networkErrorNo::REMOTE_NOT_ACTIVED, arg);
        return;
    }
    
    std::thread thread(&socket::reciveHandler,this);
    thread.detach();
}

void socket::send(const data& dt){
    if(this->socketfd <=0 ){
//        this->dispatchNetworkError(onNetworkError::networkErrorNo::NETWORk_DISCONNECT);
        args arg(nullptr);
        this->dispatch(onNetworkError::networkErrorNo::NETWORk_DISCONNECT, arg);
    }
    
    if (dt.len>0 && dt.data !=nullptr ) {
        
        char headbyte[head];
        
        //分析头
        for (int i = 0; i < head; i++ ) {
            headbyte[head - i - 1 ] = (char)(dt.len >> (i * 8));
        }
        
        //发送异常信号拦截
        struct sigaction act, oact;
        act.sa_handler = sigleHandler;
        sigemptyset(&act. sa_mask);
        act.sa_flags = 0;
        sigaction(SIGPIPE, &act, &oact);
        
        if(!::send(this->socketfd, (const char*)(dt.data), dt.len + head, MSG_DONTWAIT)){
//            this->dispatchNetworkError(onNetworkError::networkErrorNo::NETWORk_DISCONNECT);
            args arg(nullptr);
            this->dispatch(onNetworkError::networkErrorNo::NETWORk_DISCONNECT, arg);
        }
    }
}

void socket::shutdown(){
    ::shutdown(this->socketfd, SHUT_RDWR);
    this->socketfd = 0;
}

bool socket:: isActived(){
    return this->socketfd > 0;
}

void socket:: sigleError(int i){
//    this->dispatchNetworkError(onNetworkError::networkErrorNo::NETWORk_DISCONNECT);
    args arg(nullptr);
    this->dispatch(onNetworkError::networkErrorNo::NETWORk_DISCONNECT, arg);
}

void socket::reciveHandler(){
    
    auto tcpRecive =  [](socket *tcp){
        unsigned char* buf = new unsigned char[buflen];
        data *dt =  new data();
        
        auto dispatch = [=](socket *d_socket,data *dt){
            
        };
        
        //如果返回为空,package list
        auto processDataFun = [=](socket *pfd_socket,data* dt,unsigned char* readBytes,long len){
        LOOP_PROCESS_DATA:
            if(dt->len == 0) {
                //todo
                dt->len |= (unsigned char)*readBytes; readBytes++ ;len--;  dt->len<<= 8;
                dt->len |= (unsigned char)*readBytes; readBytes++ ;len--;  dt->len<<= 8;
                dt->len |= (unsigned char)*readBytes; readBytes++ ;len--;  dt->len<<= 8;
                dt->len |= (unsigned char)*readBytes; readBytes++ ;len--;
            }
            
            if(dt->len - dt->pointer > len) {
                memccpy(dt->data + dt->pointer, readBytes, (int)len, 1);
                dt->pointer += len;
                len = 0;
            }else {
                int copyLen =dt->len - dt->pointer;
                memccpy(dt->data + dt->pointer, readBytes,copyLen , 1);
                dispatch(pfd_socket,dt);
                delete dt;
                dt =  new data();
                
                readBytes += copyLen ;
                len -= copyLen;
                
                goto LOOP_PROCESS_DATA;
            }
            return dt;
        };
        
        
        if(tcp->socketfd) {
//            tcp->dispatchNetworkError(onNetworkError::networkErrorNo::NETWORk_DISCONNECT);
            args arg(nullptr);
            tcp->dispatch(onNetworkError::networkErrorNo::NETWORk_DISCONNECT, arg);
            delete dt;
            return false; //exit recive thread
        }
        
        bzero(&buf, buflen);
        long res = ::read(tcp->socketfd, buf, buflen);
        
        while (res == buflen) {
            dt = processDataFun(tcp,dt,buf,res);
            res = ::read(tcp->socketfd, buf, buflen);
        }
        
        if (res > 0) {
            dt = processDataFun(tcp,dt,buf,res);
        }
        
        usleep(readSpan * 1000); //Once every 15 seconds to handle receiving task.
        
        //Whether or not to continue processing.
        return true;
    };
    
    auto udpRecive = [](socket * socket){ return true;};
    
    while (true) {
        //process send sigle
        if(sigleCode != 0 ) this->sigleError(sigleCode);
        //recive remote data
        if(socket::socketType::TCP == this->m_socketType && !tcpRecive(this)) break ;
        if(socket::socketType::UDP == this->m_socketType&&!udpRecive(this)) break;
    }
    
//    this->dispatchNetworkError(onNetworkError::onNetworkError::NETWORk_DISCONNECT);
    args arg(nullptr);
    this->dispatch(onNetworkError::onNetworkError::NETWORk_DISCONNECT, arg);
}

void socket::bind(event& event){
    events.insert(eventMap::value_type(event.getHashCode(),&event));
}

void socket::removeBind(event& event){
    events.erase(event.getHashCode());
}

//int socket::dispatchError(event::eventType eventType,onNetworkError::networkErrorNo err){
//    eventMap::iterator iter = events.begin();
//    while (iter!= events.end()) {
//        event* e =&(*iter->second);
//        if (e->getEventType() ==  eventType)
//            e->invork();
//    }
//    return 1;
//}
//
//int socket::dispatchNetworkError(onNetworkError::networkErrorNo err){
//    this->socketfd = -1;
//    return this->dispatchError(event::eventType::NETWORK_ERROR, err);
//}
//
//int socket::dispatchReciveEvent(socket::data &data){
//    eventMap::iterator iter = events.begin();
//    while (iter!= events.end()) {
//        event* e =&(*iter->second);
//        if (e && e->getEventType() ==  socket::event::eventType::RECIVE){
//            e->setData(data.data, data.len);
//            e->invork();
//        }
//    }
//    return 1;
//
//}
