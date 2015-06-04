#ifndef XSE_CORE_STREAM_H
#define XSE_CORE_STREAM_H

#include <XSE/config.h>

XSE_NS_EXT(CORE_NS_NAME)

class Stream
{
public:
    virtual ~Stream(void){};
    
    virtual ULONG Read(UINT size_,BYTES buff_out_) = 0;

    virtual Bool Eof() = 0;
    virtual Bool Valid() = 0;
    virtual void Close() = 0;
        virtual void Write(const BYTES bytes,UINT len) = 0;
};

class StreamBuf:public Stream{
public:
    virtual ULONG GetLength() = 0;
};

XSE_NS_EXT_END

#endif
