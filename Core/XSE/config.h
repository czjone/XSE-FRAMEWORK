#ifndef XSE_PROTOBUF_CONFIG_H
#define XSE_PROTOBUF_CONFIG_H 1

#define XSE_VERSION 0.0.1

//平台宏
#define XSE_PLATFORM_TAG_ANDROID   1
#define XSE_PLATFORM_TAG_iOS       2
#define XSE_PLATFORM_TAG_MAC       3
#define XSE_PLATFORM_TAG_WIN       4
#define XSE_PLATFORM_TAG_LINUX     5
#define XSE_PLATFORM_TAG_UNKONW    0

//外部定义的宏
/*
//suppurt platform
#define ANDROID
#define iOS
#define MAC
#define WINX
#define LINUX

//Feature supports
#define XSE_PROTOBUF
#define XSE_TCP
#define XSE_UDP
#define XSE_ARC
*/


//外部开关宏支持
#if XSE_PLATFORM == ANDROID
#   define  XSE_PLATFORM_TAG XSE_PLATFORM_TAG_ANDROID
#elif XSE_PLATFORM == iOS
#   define  XSE_PLATFORM_TAG XSE_PLATFORM_TAG_iOS
#elif XSE_PLATFORM == MAC
#   define  XSE_PLATFORM_TAG XSE_PLATFORM_TAG_MAC
#elif XSE_PLATFORM == WINX
#   define  XSE_PLATFORM_TAG XSE_PLATFORM_TAG_WIN
#elif XSE_PLATFORM == LINUX
#   define  XSE_PLATFORM_TAG XSE_PLATFORM_TAG_LINUX
#else
#   define XSE_PLATFORM_TAG  XSE_PLATFORM_TAG_UNKONW
#endif

#ifndef XSE_PLATFORM_TAG
#   define XSE_PLATFORM_TAG XSE_PLATFORM_TAG_UNKONW
#endif

//命名空间支持
#define XSE_NS_ROOT Xse
#define XSE_NS_BEGIN Xse {
#define XSE_NS_END }
#define XSE_NS_USING using namespace Xse;

//扩展名字空间
#define XSE_NS_EXT(name) namespace Xse { namespace name {
#define XSE_NS_EXT_END }}
#define XSE_NS_EXT_USING(name) using namespace Xse; using namespace name;


//PROPERTY
#define PROPERTY_SUPPER_DEF(R_LEVEL,W_LEVEL,NAME,TYPE)                  \
    private:                                                            \
        TYPE m_property_##NAME;                                         \
    W_LEVEL :                                                           \
        virtual void set##NAME(TYPE val){                               \
            this->m_property_##NAME = val;                              \
        };                                                              \
                                                                        \
    R_LEVEL :                                                           \
        virtual TYPE get##NAME(void){                                   \
            return this->m_property_##NAME;                             \
        }                                                               \

#define PROPERTY_DEF(name,type)            PROPERTY_SUPPER_DEF(public,public,name,type)
#define PROPERTY_ONLY_READ_DEF(name,type)  PROPERTY_SUPPER_DEF(public,private,name,type)

//types
typedef int             INT;
typedef unsigned int    UINT;
typedef unsigned long   ULONG;
typedef float           FLOAT;
typedef double          DOUBLE;
typedef INT             Bool;
typedef unsigned char   BYTE;
typedef unsigned char*  STRING;
typedef unsigned char*  BYTES;
typedef INT  status;

//#define XSE_LOG(msg,...) print(msg,__VA_ARGS__) //c99
#include <stdio.h>
#define XSE_LOG(msg,args...) fprintf(stderr,msg,##args) //GCC
#define XSE_ASSERT(EXP,MSG) \
    if(!(EXP)) XSE_LOG("ASSERT FAIL: %s",MSG)

//other
#define CORE_NS_NAME Core


// status
#define STATUS_OK 0
#define STATUS_UNKNOW_ERROR -1

#define  DELETE(p) if((p)) {delete (p);(p)=nullptr;}
#define  DELETE_ARRAY(p) if((p)) {delete[] (p);(p)=nullptr;}

#endif//(end XSE_PROTOBUF_CONFIG_H)