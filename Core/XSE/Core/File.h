#ifndef XSE_CORE_IO_FILE_H
#define XSE_CORE_IO_FILE_H

#include <XSE/config.h>
#include <XSE/Core/Array.h>
#include <XSE/Core/Stream.h>

XSE_NS_EXT(CORE_NS_NAME)
namespace IO {
    class File {
    public:
        enum Model{
            FILE = 0x01,
            DIR = 0x02,
            UNKNOW = 0x00,
            UNKNOW_PLATFORM = 0x05,
            NOT_FOUND = 0x04,
        };
    private:
        Stream * m_stream;
        Model m_model;
        STRING m_path;
    private:
        File(STRING path);
        virtual ~File(void);
        Stream& getStream();
        void flush();
        void close();
        
    public:
        Model getModel();
        
        //static
        static File& OpenFile(STRING path);
        static void Close(File*file);
        static Bool exist(STRING path);
        static Model getFileModel(STRING path);
//        static Array<File*> getFiles(STRING dir);
        static status createFile(STRING);
        static status createFile(STRING,Stream&);
        static status createDir(STRING path);
        static const STRING getDomainsDir();
    };

}
XSE_NS_EXT_END

#endif