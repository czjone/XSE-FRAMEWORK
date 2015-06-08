#ifndef XSE_SERIALIZATION_BASE_H
#define XSE_SERIALIZATION_BASE_H
#include <XSE/Core/Serialization.h>

XSE_NS_EXT_USING(CORE_NS_NAME);

////////////////////////////////////////////////////////////////
//Serialization::value
////////////////////////////////////////////////////////////////

//STRING STD_STRING_TO_STRING(std::string& str){
//    INT size = str.length();
//    STRING _str = new BYTE[size];
//    memccpy(_str, (const char*)(str.c_str()), 0, (size_t)size);
//    return _str;
//};

Serialization::value::value(Serialization* ser,std::string key){
    std::map<std::string,value*>::value_type _value(key,this);
    ser->m_values.insert(_value);
    this->m_bindSer = ser;
    this->m_value = nullptr;
    this->key = std::string(key);
};

Serialization::value:: ~value (void){
    this->deletePtr();
    this->m_bindSer->m_values.erase(this->key);
};

template<typename T>
T& Serialization::value::getValue(std::string key){
    std::map<std::string,value*>::iterator  _value=m_bindSer->m_values.find(key);
    return (T&)(_value->second->m_value);
};

void Serialization::value::deletePtr(){
    if(this->isArray == VALUE_BOOL_TRUE) {DELETE_ARRAY(m_value);}
    else {DELETE(m_value);}
};

template<typename T>
void Serialization::value::setValue(T val){
    this->m_value = (T*)(new T(val));
    this->isArray = false;
};

template<typename T>
void Serialization::value::setValue(STRING val){
    size_t size =strlen((const char*)val);
    this->m_value = new BYTE[size];
    memcpy(this->m_value, val,size );
};

template<typename T>
void Serialization::value::setValue(std::string val){
    size_t size =val.length();
    this->m_value = new BYTE[size];
    memcpy(this->m_value, (const char*)val.c_str(), size);
    this->isArray = true;
}

////////////////////////////////////////////////////////////////
//Serialization::value
////////////////////////////////////////////////////////////////
template<typename T>
T* Serialization::Load(BYTES bytes){
    T *t = new T();
    t->LoadProcess(bytes);
    return t;
}

template<typename T>
T* Serialization::Load(StreamBuf& stream){
    T *t = new T();
    BYTES bytes = stream.getBytes();
    t->LoadProcess(bytes);
    return t;
}


template<typename T>
T* Serialization::Load(const Stream& stream){
    T * t = new T();
    return t;
}

template<typename T>
T* Serialization::Load(Stream& file){
    T * t = new T();
    return t;
}

void Serialization::Save(std::string file){
    XSE_ASSERT(false, "TODO::等待处理");
}
void Serialization::Save(StreamBuf& stream){
    XSE_ASSERT(false, "TODO::等待处理");
}
void Serialization::Save(Stream& stream){
    XSE_ASSERT(false, "TODO::等待处理");
}

#endif

