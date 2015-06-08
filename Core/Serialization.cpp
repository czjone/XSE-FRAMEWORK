#include <XSE/Core/Serialization.h>
#include "mxml.h"
#include "json.h"

XSE_NS_EXT_USING(CORE_NS_NAME);
///////////////////////////////////////////////////////////////
//XMLSerialization
////////////////////////////////////////////////////////////////


XMLSerialization::XMLSerialization(){
    
    XSE_ASSERT(false, "TODO::等待处理");
}

XMLSerialization::XMLSerialization(StreamBuf& stream){
    
    XSE_ASSERT(false, "TODO::等待处理");
}
XMLSerialization::XMLSerialization(StdFileStream& stream){
    XSE_ASSERT(false, "TODO::等待处理");
    
}
XMLSerialization::XMLSerialization(STRING filename){
    
    XSE_ASSERT(false, "TODO::等待处理");
}

XMLSerialization:: ~XMLSerialization(void){
    XSE_ASSERT(false, "TODO::等待处理");
};

void XMLSerialization::SaveProcess(std::map<std::string, value*>& values){
    XSE_ASSERT(false, "TODO::等待处理");
}

void XMLSerialization::LoadProcess(BYTES bytes){
    XSE_ASSERT(false, "TODO::等待处理");
}

////////////////////////////////////////////////////////////////
//XMLSerialization
////////////////////////////////////////////////////////////////


JSONSerialization::JSONSerialization(){
    XSE_ASSERT(false, "TODO::等待处理");
}

JSONSerialization::JSONSerialization(StreamBuf& stream){
    XSE_ASSERT(false, "TODO::等待处理");
}
JSONSerialization::JSONSerialization(StdFileStream& stream){
    XSE_ASSERT(false, "TODO::等待处理");
    
}
JSONSerialization::JSONSerialization(STRING filename){
    
    XSE_ASSERT(false, "TODO::等待处理");
}

JSONSerialization:: ~JSONSerialization(void){
    XSE_ASSERT(false, "TODO::等待处理");
}

void JSONSerialization::SaveProcess(std::map<std::string, value*>& values){
    XSE_ASSERT(false, "TODO::等待处理");
    
}

void JSONSerialization::LoadProcess(BYTES bytes){
    XSE_ASSERT(false, "TODO::等待处理");
}

////////////////////////////////////////////////////////////////
//YAMLSerialization
////////////////////////////////////////////////////////////////
YAMLSerialization::YAMLSerialization(){
    XSE_ASSERT(false, "TODO::等待处理");
}

YAMLSerialization::YAMLSerialization(StreamBuf& stream){
    XSE_ASSERT(false, "TODO::等待处理");
}
YAMLSerialization::YAMLSerialization(StdFileStream& stream){
    XSE_ASSERT(false, "TODO::等待处理");
}
YAMLSerialization::YAMLSerialization(STRING filename){
    XSE_ASSERT(false, "TODO::等待处理");
}

YAMLSerialization:: ~YAMLSerialization(void){
    XSE_ASSERT(false, "TODO::等待处理");
}

void YAMLSerialization::SaveProcess(std::map<std::string, value*>& values) {
    XSE_ASSERT(false, "TODO::等待处理");
}

void YAMLSerialization::LoadProcess(BYTES bytes) {
    XSE_ASSERT(false, "TODO::等待处理");
    
}
