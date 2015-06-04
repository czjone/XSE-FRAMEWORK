#ifndef XSE_CORE_COMPRESS_H
#   define XSE_CORE_COMPRESS_H


//#include <stdio.h>
//#include <iostream>
//#include <streambuf>

#include <XSE/config.h>
#include <XSE/Core/Stream.h>

XSE_NS_EXT(CORE_NS_NAME)

class Zip{
private:
    Zip(){};
    virtual ~Zip(void){};
    
public:
    //core fuctions.
    static status Compress(Stream &instream,Stream& ostream);
    static status Compress(STRING ifileName,STRING ofileName);
    static status Compress(STRING ifileName,Stream& ostream);
    static status Compress(Stream &instream,Stream fileName);
    static status Compress_DIR(STRING dir,Stream& ostrem);
    static status Compress_DIR(STRING dir,STRING ofileName);
    
    static status UnCompress(Stream &instream,Stream& ostream);
    static status UnCompress(STRING ifileName,STRING ofileName);
    static status UnCompress(STRING ifileName,Stream& ostream);
    static status UnCompress(Stream &instream,STRING ofileName);
    static status UnCompress_DIR(Stream& instream,STRING dir);
    static status UnCompress_DIR(Stream &instream,Stream& ostream);
};
XSE_NS_EXT_END
#endif /* defined(__XSE_PROJECT__Zip__) */
