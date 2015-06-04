
#ifndef XSE_PROJECT_input_h
#define XSE_PROJECT_input_h

class input : public dispather{
    swallowMessage();
};

class Mouse:public input{
    
};

class KeyBord:public input{
    
};

class Touch:public input{
    class TouchInput:public Event{
        
    };
    
    
};

class COM:public input{
    
};

class Other {
    class HOME {
        
    };
    
    class MENU {
        
    };
    
    class VOLUEUP{
        
    }
    
    class VOLUMEDOWN{
        
    }
    
    class Return{
        
    };
    
    class PowerOff{
        
    };
    
    //震动开关输入
    class vibration{
        
    };
};

class InputEvent

{
public: KeyBord;
public: Touch;
public: COM;
public: Other;
};

#endif
