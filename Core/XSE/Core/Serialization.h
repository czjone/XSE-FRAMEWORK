#ifndef XSE_PROJECT_Serialization_h
#   define XSE_PROJECT_Serialization_h
#   include <XSE/config.h>
#   include <string>
#   include <XSE/Core/Stream.h>
#   include <XSE/Core/StdFileStream.h>
#   include <Map>
#   include <array>
#   include <vector>

#   define  SERIALIZATION_PROPERTY_SUPPER_DEF(R_LEVEL,W_LEVEL,NAME,TYPE)       \
private: \
Serialization::value m_ser_property_##NAME = value(this, #NAME);\
W_LEVEL :\
inline TYPE get##NAME(void) {\
return this->m_ser_property_##NAME.getValue<TYPE>(#NAME);\
};\
R_LEVEL :\
inline void set##NAME(TYPE val) {\
this->m_ser_property_##NAME.setValue<TYPE>(val);\
};\


XSE_NS_EXT(CORE_NS_NAME)

class Serialization {
protected:
    class value {
    private:
        std::string key;
        Serialization* m_bindSer;
        void * m_value;
        Bool isArray = false;
        
        void deletePtr();
        
    public:
        value(Serialization* ser,std::string key);
        virtual ~value (void);
        
        template<typename T>
        inline T& getValue(std::string key);
        
        template<typename T>
        inline void setValue(T val);
        
        template<typename T>
        inline void setValue(STRING val);
        
        template<typename T>
        inline void setValue(std::string val);
    };
    
    friend class value;
    
protected:
    std::map<std::string, value*> m_values;
    virtual void SaveProcess(std::map<std::string, value*>& values) = 0;
    virtual void LoadProcess(BYTES bytes) = 0;
    
public:
    template<typename T>
    static T* Load(BYTES bytes);
    
    template<typename T>
    static T* Load(StreamBuf& stream);
    
    template<typename T>
    static T* Load(const Stream& stream);
    
    template<typename T>
    static T* Load(Stream& file);
    
    static void Save(std::string file);
    static void Save(StreamBuf& stream);
    static void Save(Stream& stream);
};

class XMLSerialization : public Serialization{
protected:
    virtual void SaveProcess(std::map<std::string, value*>& values);
    virtual void LoadProcess(BYTES bytes);
public:
    XMLSerialization();
    XMLSerialization(StreamBuf& stream);
    XMLSerialization(StdFileStream& stream);
    XMLSerialization(STRING filename);
    
    virtual ~XMLSerialization(void);
};

class JSONSerialization: public Serialization {
protected:
    virtual void SaveProcess(std::map<std::string, value*>& values);
    virtual void LoadProcess(BYTES bytes) ;
    
public:
    JSONSerialization();
    JSONSerialization(StreamBuf& stream);
    JSONSerialization(StdFileStream& stream);
    JSONSerialization(STRING filename);
    
    virtual ~JSONSerialization(void);
};

class YAMLSerialization :public Serialization {
protected:
    virtual void SaveProcess(std::map<std::string, value*>& values) ;
    virtual void LoadProcess(BYTES bytes) = 0;
    
public:
    YAMLSerialization();
    YAMLSerialization(StreamBuf& stream);
    YAMLSerialization(StdFileStream& stream);
    YAMLSerialization(STRING filename);
    
    virtual ~YAMLSerialization(void);
    
};

#include <serialization.inl>

XSE_NS_EXT_END

#endif
