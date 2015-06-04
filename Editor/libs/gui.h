#ifndef XSE_EDITOR_GUI_H
#   define XSE_EDITOR_GUI_H
#   include "config.h"
#   include <string>
#   include <map>
#   define XSE_NS_GUI GUI

XSE_NS_EXT(XSE_NS_GUI)

class Engine {
public:
    /*
     @parmer default is main.cfg
     */
    Engine();
    Engine(std::string& cfg);
    virtual ~Engine();
protected:
    virtual int ProcessRun(void);
public:
    inline int Run(){return this->ProcessRun();};
};

XSE_NS_EXT_END

#endif
