#include <XSE/Core/Event.h>

XSE_NS_EXT_USING(CORE_NS_NAME);

static INT ID = 0;

eventListener::eventListener():m_property_Id(ID++),m_property_Type(0){

}

//typedef std::map<UINT, Events> eventManager;
//static eventManager dispatherManager;

/***********************************************
dispather
***********************************************/

dispather::dispather(){
    
}

dispather::~dispather(){
    
}


void dispather::dispatch(args&){
    
}

void dispather::dispatch(INT type,args& arg){
    EventsIterator itor = m_event.begin();
    while (itor!=m_event.end()) {
        if((*itor)->getType() == type){
            (*itor)->Invork(arg);
        }
        itor++;
    }
}

void dispather::addEventListenner(eventListener& listenner){
    EventsIterator itor = m_event.begin();
    while (itor!=m_event.end()) {
        XSE_ASSERT((*itor) == &listenner, "listenner is exist.");
        itor++;
    }
    
    m_event.push_back(&listenner);
}

void dispather::removeEventListenner(eventListener& listenner){
    EventsIterator itor = m_event.end();
    while (itor!=m_event.begin()) {
        if ((*itor)->getId() == listenner.getId()) {
            m_event.erase(itor);
        }
        itor--;
    }
}