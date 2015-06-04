#ifndef XSE_CORE_NETWORK_SOCKET_H
#   define XSE_CORE_NETWORK_SOCKET_H

#include <XSE/config.h>
#include <XSE/Core/Event.h>
#include <map>


XSE_NS_EXT(CORE_NS_NAME)

namespace network{
    
    class socket : public dispather {
        
    public:
        
        struct data{
            
            friend class socket;
            
        public:
            unsigned int len;
            unsigned char* data;
        private:
            unsigned pointer;
            
        };
        
        
    private:
        
        class event: public eventListener {
            
            friend class socket;
            
        public:
            enum eventType {
                RECIVE,
                NETWORK_ERROR,
            };
            
        protected:
            
            virtual void invork(args&) = 0;
            void setData(unsigned char* bytes,unsigned int len );
            
        protected:
            unsigned char* m_bytes;
            unsigned int m_len;
            unsigned int hashCode;
            eventType m_eventType;
            
        public:
            virtual ~event();
            inline bool operator==(event&right){
                return this->hashCode == right.hashCode;
            }
            
            inline int getHashCode() {
                return this->hashCode;
            }
        };
        
        
    public:
        class reciveEvent:public event{
            
        protected:
            virtual void invork(args&);
        };
        
        class onNetworkError: event {
            
        public:
            enum networkErrorNo :UINT{
                REMOTE_NOT_ACTIVED = 0x01,
                LOCAL_NETWORK_PORT_ERROR =0x02,
                NETWORk_DISCONNECT = 0x03,
            };
            
        public:
            
            onNetworkError();
            onNetworkError(networkErrorNo erro);
            
        protected:
            virtual void invork(args&);
            virtual void onError(networkErrorNo err) = 0;
        };
        
    public:
        enum socketType{
            TCP = 0x00,
            UDP =0x01,
        };
        
        
        typedef std::map<int, event*> eventMap;
        typedef std::map<int, event*>::iterator eventIterator;
        
    private:
        unsigned char * m_ip;
        unsigned int port;
        int socketfd;
        socketType m_socketType;
        eventMap events;
    private:
        void sigleError(int);
        void reciveHandler();
    public:
        socket(unsigned char* ip,unsigned int port);
        socket(unsigned char* ip,unsigned int port,socketType type);
        virtual ~socket();
        void connect();
        
        void send(const data& dt);
        void shutdown();
        bool isActived();
        void bind(event& event);
        void removeBind(event& event);
        //    protected:
        //        int dispatchError(event::eventType eventType,onNetworkError::networkErrorNo err);
        //        int dispatchNetworkError(onNetworkError::networkErrorNo err);
        //        int dispatchReciveEvent(data& dt);
    };
}

XSE_NS_EXT_END

#endif /* defined(XSE_NETWORK_SOCKET_H) */
