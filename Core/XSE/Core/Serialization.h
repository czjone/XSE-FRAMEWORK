#ifndef XSE_CORE_SERIALIZATION_H
#define XSE_CORE_SERIALIZATION_H

#include <XSE/config.h>

XSE_NS_EXT_BEGINE(CORE_NS_NAME)

class Serialization {
public:
    template<typename T>
    inline void Save(){
        
    };
    
    template<typename T>
    inline T Load(){
        
    };

    
};

class DeSerialization {
    
};

class XmlSerialization :public Serialization {
    
};

class JSONSerialization:public Serialization{
    
};

class YAMLSerialization :public Serialization{
    
};

class XmlDeSerialization :public DeSerialization {
    
};

class JSONDeSerialization:public DeSerialization{
    
};

class YAMLDeSerialization :public DeSerialization{
    
};

XSE_NS_EXT_END


#endif
