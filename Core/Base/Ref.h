#ifndef __XSE_PROJECT__Ref__
#define __XSE_PROJECT__Ref__
#include <XSE/config.h>

XSE_NS_EXT(CORE_NS_NAME)

class Ref{
    
public:
    Ref(void);
    virtual ~Ref(void);
    void Retain();
    void Release();
    
    PROPERTY_SUPPER_DEF(public, protected, refCount, UINT);
};

XSE_NS_EXT_END

#endif /* defined(__XSE_PROJECT__Ref__) */
