#   include <XSE/Core/File.h>
#   include <XSE/Core/StdFileStream.h>

#   include <sys/stat.h>
#   include <unistd.h>
#   include <stdio.h>
#   include <stdlib.h>

XSE_NS_EXT_USING(CORE_NS_NAME);

IO::File::File(STRING path):m_path(path){
    
}
IO::File::~File(void){
    if(!m_stream->Eof()){
        this->flush();
    }
    DELETE(m_stream);
}

Stream& IO::File::getStream(){
    XSE_ASSERT(m_model == Model::FILE,"Folder can't read with stream");
    if(!m_stream){
//        m_stream =  new StdFileStream(m_path);
    }
    return *m_stream;
}
void IO::File::flush(){
    
}
void IO::File::close(){
    
}

IO::File::Model IO::File::getModel(){
    return IO::File::getFileModel(m_path);
}

//static
IO::File& IO::File::OpenFile(STRING path){
    File * file = new File(path);
    return *file;
}

void IO::File::Close(File*file){
    if(file) file->flush();
    DELETE(file);
}

Bool IO::File::exist(STRING path){
    //TOODO:: add Other platform support.
#if(XSE_PLATFORM_TAG == XSE_PLATFORM_TAG_MAC)
    return access((const char *)path, F_OK);
#endif
    return STATUS_UNKNOW_ERROR;
}

IO::File::Model IO::File::getFileModel(STRING path){
    if (!File::exist(path)) return Model::NOT_FOUND;
    //TOODO:: add Other platform support.
#if(XSE_PLATFORM_TAG == XSE_PLATFORM_TAG_MAC)
    struct stat st;
    printf("%s",argv[1]);
    stat(path,&st);
    if (S_ISDIR(st.st_mode)) return Model::DIR;
    else return Model::File;
    return Model::UNKNOW;
#else
    return Model::UNKNOW_PLATFORM;
#endif
    
}

//Array<File*> IO::File::getFiles(STRING dir)
//{
//    Array<File*> files;
//    return files;
//}

status IO::File::createFile(STRING path){
    //    ::File * file = fopen((<#const char *#>)STRING, "wb+");
    return STATUS_UNKNOW_ERROR;
}

status IO::File::createFile(STRING path,Stream&){
    
    return STATUS_UNKNOW_ERROR;
}
status IO::File::createDir(STRING path){
    //TODO::add Other platform support.
    return STATUS_UNKNOW_ERROR;
}

const STRING IO::File::getDomainsDir(){
    //TODO::add Other platform support.
    return ( unsigned char*)"";
}
