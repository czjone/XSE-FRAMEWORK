#ifndef XSE_CORE_BASE_EVENT_H
#   define XSE_CORE_BASE_EVENT_H
#   include <XSE/config.h>
#   include <map>
#   include <vector>

XSE_NS_EXT(CORE_NS_NAME)

class dispather;
class eventListener;

typedef std::vector<eventListener*> Events;
typedef std::vector<eventListener*>::iterator EventsIterator;
typedef UINT EventType;

class args{
public:
    args(void* data);
    void * data;
};

class eventListener{
    
    friend class dispather;
    
    PROPERTY_ONLY_READ_DEF(Priority, UINT);
    PROPERTY_SUPPER_DEF(public, protected, Id, UINT);
    PROPERTY_SUPPER_DEF(public, public, Type, UINT);
    
public:

    eventListener();
    
protected:
    virtual UINT getEventType(void) = 0;
    
    inline Bool operator == (eventListener& e){
        return this->getId() == e.getId();
    };
    virtual UINT Invork(args&) = 0;
};

class dispather{
    
    PROPERTY_ONLY_READ_DEF(events, Events);
    
private:
    Events m_event;
    
protected:
    
    dispather();
public:
    virtual ~dispather();
    void addEventListenner(eventListener&);
    void removeEventListenner(eventListener&);
    
protected:
    void dispatch(args&);
    void dispatch(INT type,args&);
};
XSE_NS_EXT_END

#endif /* defined(__XSE_PROJECT__Event__) */
