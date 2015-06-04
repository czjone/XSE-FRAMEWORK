#include <XSE/Core/StdFileStream.h>

XSE_NS_EXT_USING(CORE_NS_NAME);



StdFileStream::~StdFileStream(void){
    if(m_file)fclose(m_file);
}


StdFileStream::StdFileStream(const STRING szPath)
{
    m_file = fopen((const char*)szPath,"rb+");
    if(m_file)
    {
        //计算文件长度
        m_iLen = ftell(m_file);
        fseek(m_file,0,SEEK_END);
        m_iLen = ftell(m_file) - m_iLen;
        fseek(m_file,0,SEEK_SET);
    }
    else
    {
        m_iLen = 0;
    }
}

Bool StdFileStream::Valid()
{
    return m_iLen > 0;
}

Bool StdFileStream::Eof()
{
    return feof(m_file);
}

ULONG StdFileStream::GetLength()
{
    return m_iLen;
}

ULONG StdFileStream::Read(UINT size_,BYTES buff_out_)
{
    return fread(buff_out_,1,size_,m_file);
}
