#ifndef XSE_CORE_STDFILESTREM_H
#   define XSE_CORE_STDFILESTREM_H
#   include <XSE/config.h>
#   include <XSE/Core/Stream.h>

XSE_NS_EXT(CORE_NS_NAME)

class StdFileStream :public Stream
    {
    private:
        FILE * m_file;
        unsigned long m_iLen;
        
    public:
        virtual ~StdFileStream(void);
        
        StdFileStream(const STRING path);
        virtual Bool Valid();
        virtual Bool Eof();
        virtual ULONG GetLength();
        virtual ULONG Read(UINT size_,BYTES buff_out_);
        virtual void Close() {};
        virtual void Write(const BYTES bytes,UINT len) {};
        
    };

XSE_NS_EXT_END

#endif
