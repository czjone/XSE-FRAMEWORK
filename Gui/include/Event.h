#ifndef XSE_PROJECT_Event_h
#define XSE_PROJECT_Event_h
class eventListener{
    
public:
    class args{
        
    };
    
    enum Type{
        
    };
    
protected:
    virtual eventListener::Type getEventType(void) = 0;
};

class dispather{
    typedef std::map<eventListener::Type, eventListener> events;
    typedef std::map<dispather, events> eventManager;
    typedef std::map<dispather, eventListener>::iterator eventsIterator;
    
    PROPERTY_ONLY_READ_DEF(events, events);
    
protected:
    dispather();
public:
    virtual ~dispather();
protected:
    void dispatch(eventListener::Type,eventListener::args&);
    void dispatch();
public:
    void addEventListenner(eventListener&);
    void removeEventListenner(eventListener&);
    void removeEventListenner(eventListener::Type);
    
protected:
    static eventManager dispatherManager;
};


#endif
