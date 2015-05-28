#ifndef _XSE_DIRECTORY_H
#define _XSE_DIRECTORY_H 1

#include <Map>

namespace Xse {
    namespace IO {
        
        enum Type{
            FILE,
            DIRECTORY,
        };
        
        class Dirctory{
        private:
            Dirctory();
            virtual ~Dirctory();
        public:
            static void Create(const char*);
            static void Exits(const char*);
            static void Delete(const char*);
            static void Move(const char* src,const char * des);
            static Type getType(const char*);
            static std::Map<const char* path,Type> getMap(const char*);
        };
    }
}
#endif /* _XSE_DIRECTORY_H.h */