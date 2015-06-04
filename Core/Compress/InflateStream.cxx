#include <XSE/Core/InflateStream.h>
#include <stdlib.h>
#include <string.h>



XSE_NS_EXT_USING(CORE_NS_NAME);

#define CHUNK_SIZE 1024ui

InflateStream::InflateStream(const STRING file)
{
    m_origStream = new StdFileStream(file);
    m_indeflateBuff = (BYTES)(malloc(CHUNK_SIZE));
    m_origBuff = (BYTES)malloc(CHUNK_SIZE);
    
    memset(&m_stream,0,sizeof(m_stream));
    inflateInit(&m_stream);
    m_last_inflate_ = Z_OK;
};

InflateStream::InflateStream(Stream& stream)
{
    m_origStream = &stream;
    m_indeflateBuff = (unsigned char *)malloc(CHUNK_SIZE);
    m_origBuff = (unsigned char *)malloc(CHUNK_SIZE);
    
    memset(&m_stream,0,sizeof(m_stream));
    inflateInit(&m_stream);
    m_last_inflate_ = Z_OK;
};


InflateStream::~InflateStream()
{
    free(m_indeflateBuff);
    free(m_origBuff);
};

UINT InflateStream::Inflate(unsigned char * _buff_out,UINT _block_size)
{
    m_stream.next_out = _buff_out;
    m_stream.avail_out = (INT)_block_size;
    m_last_inflate_ = inflate(&m_stream,Z_NO_FLUSH);
    /*
     #define Z_OK            0
     #define Z_STREAM_END    1
     #define Z_NEED_DICT     2
     #define Z_ERRNO        (-1)
     #define Z_STREAM_ERROR (-2)
     #define Z_DATA_ERROR   (-3)
     #define Z_MEM_ERROR    (-4)
     #define Z_BUF_ERROR    (-5)
     #define Z_VERSION_ERROR (-6)
     */
    if(m_last_inflate_ > Z_STREAM_END)return STATUS_OK;
    return _block_size - m_stream.avail_out;
};

UINT InflateStream::Inflate(char * buff_out,UINT size_)
{
    int inflate_bytes = 0;
    static int i = 0;
    do
    {
        ULONG orig_bytes = 0;
        if(!m_stream.avail_in)
        {
            orig_bytes = m_origStream->Read(CHUNK_SIZE,m_origBuff);
            m_stream.avail_in = CHUNK_SIZE;
            m_stream.next_in = m_origBuff;
        }
        
        do
        {
            i++;
            ULONG bytes_read = 0;
            memset(m_indeflateBuff,0,CHUNK_SIZE);
            bytes_read = Inflate(m_indeflateBuff,size_ - inflate_bytes);
            XSE_ASSERT(bytes_read,"read file fail.");
            memcpy(buff_out+inflate_bytes,m_indeflateBuff,bytes_read);
            inflate_bytes += bytes_read;
            if(inflate_bytes >=size_)  return size_;
            else if(m_last_inflate_ == Z_STREAM_END) return inflate_bytes;
            
        }while(m_stream.avail_in);
        
    }while(m_last_inflate_ != Z_STREAM_END);
    
    return 0;
};

Bool InflateStream::Eof()
{
    return this->m_last_inflate_ == Z_STREAM_END;
};
