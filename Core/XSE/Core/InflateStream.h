#ifndef XSE_CORE_COMPRESS_INFLATESTREAM_H
#   define XSE_CORE_COMPRESS_INFLATESTREAM_H
#   include <XSE/config.h>
#   include <zlib.h>
#   include <XSE/Core/Stream.h>
#   include <XSE/Core/StdFileStream.h>

XSE_NS_EXT(CORE_NS_NAME)

typedef z_stream ZipStream;

//压缩文件
class InflateStream
{
private:
    ZipStream           m_stream;
    Stream*             m_origStream;
    INT                 m_last_inflate_;
    BYTES               m_indeflateBuff;
    BYTES               m_origBuff;
    

public:
    InflateStream(const STRING file);
    InflateStream(Stream& stream);
    ~InflateStream();
    UINT Inflate(unsigned char * _buff_out,UINT _block_size);
    UINT Inflate(char * buff_out,UINT size_);
    Bool Eof();
};

XSE_NS_EXT_END

#endif
