
#include <zlib.h>

#include <XSE/Core/File.h>
#include <XSE/Core/InflateStream.h>
#include <XSE/Core/Zip.h>
#include <XSE/Core/StdFileStream.h>

XSE_NS_EXT_USING(CORE_NS_NAME)


status Zip::Compress(Stream &instream,Stream& ostream){
    XSE_ASSERT(nullptr,"The method to realize no");
    //TODO::Implement the logic
    return STATUS_OK;
}

status Zip::Compress(STRING ifileName,STRING ofileName){
    XSE_ASSERT(nullptr,"The method to realize no");
    //TODO::Implement the logic
    return STATUS_OK;
}

status Zip::Compress(STRING ifileName,Stream& ostream){
    XSE_ASSERT(nullptr,"The method to realize no");
    //TODO::Implement the logic
    return STATUS_OK;
}

status Zip::Compress(Stream &instream,Stream fileName){
    XSE_ASSERT(nullptr,"The method to realize no");
    //TODO::Implement the logic
    return STATUS_OK;
}

status Zip::Compress_DIR(STRING dir,Stream& ostrem){
    XSE_ASSERT(nullptr,"The method to realize no");
    //TODO::Implement the logic
    return STATUS_OK;
}

status Zip::Compress_DIR(STRING dir,STRING ofileName){
    XSE_ASSERT(nullptr,"The method to realize no");
    //TODO::Implement the logic
    return STATUS_OK;
}

status Zip::UnCompress(Stream &instream,Stream& ostream){
    InflateStream if_stream(instream);
    const INT CH_SIZE = 1024;
    BYTE buf[CH_SIZE];
    while (!if_stream.Eof()) {
        UINT size = if_stream.Inflate(buf, CH_SIZE);
        ostream.Write(buf, size);
    }
    return STATUS_OK;
}

status Zip::UnCompress(STRING ifileName,STRING ofileName){
//    IO::StdFileStream istream((const STRING)ifileName);
//    IO::StdFileStream ostream((const STRING)ofileName);
//    ZIP::UnCompress(istream,ostream);
    return STATUS_OK;
}

status Zip::UnCompress(STRING ifileName,Stream& ostream){
//    IO::StdFileStream istream((const STRING)ifileName);
//    ZIP::UnCompress(istream,ostream);
    return STATUS_OK;
}

status Zip::UnCompress(Stream &instream,STRING ofileName){
//    IO::StdFileStream ostream((const STRING)ofileName);
//    ZIP::UnCompress(istream,ostream);
    return STATUS_OK;
}

status Zip::UnCompress_DIR(Stream& instream,STRING dir){
    XSE_ASSERT(nullptr,"The method to realize no");
    //TODO::Implement the logic
    return STATUS_OK;
}

status Zip::UnCompress_DIR(Stream &instream,Stream& ostream){
    
    XSE_ASSERT(nullptr,"The method to realize no");
    //TODO::Implement the logic
    return STATUS_OK;
    
    
}

