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
#   define  XSE_PLATFORM_TAG = XSE_PLATFORM_TAG_ANDROID
#elif XSE_PLATFORM == iOS
#   define  XSE_PLATFORM_TAG = XSE_PLATFORM_TAG_iOS
#elif XSE_PLATFORM == MAC
#   define  XSE_PLATFORM_TAG = XSE_PLATFORM_TAG_MAC
#elif XSE_PLATFORM == WINX
#   define  XSE_PLATFORM_TAG = XSE_PLATFORM_TAG_WIN
#elif XSE_PLATFORM == LINUX
#   define  XSE_PLATFORM_TAG = XSE_PLATFORM_TAG_LINUX
#else
#   define XSE_PLATFORM_TAG  = XSE_PLATFORM_TAG_UNKONW
#endif

//命名空间支持
#define XSE_NS_ROOT Xse
#define XSE_NS_BEGIN Xse {
#define XSE_NS_END }
#define XSE_NS_USING using namespace Xse;

//扩展名字空间
#define XSE_NS_EXT(name) namespace Xse { namespace name {
#define XSE_NS_EXT(name) }}
#define XSE_NS_EXT_USING(name) using namespace Xse; using namespace name;

#endif//(end XSE_PROTOBUF_CONFIG_H)