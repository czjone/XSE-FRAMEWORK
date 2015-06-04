#ifndef XSE_CORE_ARRAY_H
#define XSE_CORE_ARRAY_H
#   include <XSE/config.h>
#   include <vector>


XSE_NS_EXT(CORE_NS_NAME)

template<typename T>
class Array : public std::vector<T*> {
public:
    Array(){
        
    };
    virtual ~Array(void){
        
    };
    
};

XSE_NS_EXT_END

#endif
