#ifndef XSE_PROTOBUF_CORE_CPP
#define XSE_PROTOBUF_CORE_CPP 1

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "protobuf.h"



#ifdef PROTOBUF_SUPPORT

using namespace XSE;
using namespace ProtoBuf;
using namespace std;

#define MSG_CONFIG_PREFIX ".MSG"

////////////////////////////////////////
//templates
//base
#define LANGUAGE_TEMPLATE_BASE_C(__MSG_NAME__)
#define LANGUAGE_TEMPLATE_BASE_JAVA(__MSG_NAME__)
#define LANGUAGE_TEMPLATE_BASE_CSHARP(__MSG_NAME__)

//tempate
#define LANGUAGE_TEMPLATE_STRUCTE_C(__MSG_NAME__)
#define LANGUAGE_TEMPLATE_STRUCTE_JAVA(__MSG_NAME__)
#define LANGUAGE_TEMPLATE_STRUCTE_CSHARP(__MSG_NAME__)


//////////////////////////////////////
// MessgeStructPaser
//////////////////////////////////////
MessgeStructPaser::MessgeStructPaser(const char* bytes){

}

MessgeStructPaser::~MessgeStructPaser(void){

}

Token MessgeStructPaser::getNextToken(){

}

//////////////////////////////////////
// Token
//////////////////////////////////////


Token::Type Token::GetType(){
	return this->m_type;
}


//////////////////////////////////////
// Map
//////////////////////////////////////

Map::Map(const char* key, void* value){

}

Map::~Map(){

}

void Map::Make(const * key, void value){


}

#if UTEST

extern "C" {
	TEST()
}

#endif


#endif

#endif//(end XSE_PROTOBUF_CORE_H)