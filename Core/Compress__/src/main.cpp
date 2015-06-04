#ifndef ___COMPRESS_TOOL__
#define ___MD5__GENERATE_TOOL 1

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zlib.h"
#include <assert.h>

typedef void (*outpf)(const char* inbuf,uLong inlen);

long writeToFile(FILE * file, const char* data,int len) {
    return fwrite(data, 1, len, file);
};


void compressFile(const char * inbuf,const char* outbuf,uLong inlen,outpf process) {
    uLong compressLen = compressBound(inlen + 1);
    char* buf = (char*)malloc(sizeof(char) * compressLen);
    if (!buf) {
        printf("malloc memory fail.");
    }
    if( compress((Byte*)buf, &compressLen, (Byte*)inbuf, inlen) != Z_OK ) {
        printf("compress data fail.");
    }
    if(process) {
        process(buf,compressLen);
    }
    free(buf);
}

void decompressFile(const char * inbuf,const char* outbuf,int inlen,uLong &outbuflen,outpf process){
    char* buf = (char*)malloc(sizeof(char) * outbuflen);
    if (!buf) {
        printf("malloc memory fail.");
    }
    if( uncompress((Byte*)buf, &outbuflen, (Byte*)inbuf, inlen) != Z_OK ) {
        printf("compress data fail.");
    }
    if(process) {
        process(buf,outbuflen);
    }
    free(buf);
}

int CompressDir(const char* idir,const char* odir,bool magern = false) {
#ifdef __cplusplus
    DIR* dp;
    struct dirent* dirp;
    struct stat st;
    
    if((dp = opendir(idir)) == NULL)
    {
        perror("opendir");
    }
    
    while((dirp = readdir(dp)) != NULL)
    {
        char fullname[strlen(idir)];
        memset(fullname, 0, sizeof(fullname));
        /* ignore hidden files */
        if(dirp->d_name[0] == '.') continue;
        /* if dirent is a directory, call itself */
        if(!S_ISDIR(st.st_mode)){
            //            if(_fileTree.folder == nullptr){
            //                _fileTree.folder =
            //            }
            //
            //            getFileTree(fullname);
            //                ::file* file = new  ::file();
            //                if(!file) perror("create file object error.");
            //                //            file->name =
            //                if (_fileTree.files == nullptr){
            //
            //                    _fileTree.files = file;
            //                }else  _fileTree.files->next_file = file;
        }
    }
    
#else
    printf("read file error,file: %s",file);
#endif
    
    return 1;
};

int Decompress(const char* idir,const char* odir,bool isMargen = false) {
    return 1;
};

void printdir(char *dir, int depth = 0)
{
//#if LIKE_NIX
    
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    
    if ((dp = opendir(dir)) == NULL) {
        fprintf(stderr, "Can`t open directory %s\n", dir);
        return ;
    }
    
    chdir(dir);
    while ((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 ||
                strcmp(entry->d_name, "..") == 0 )
                continue;
            printf("%*s%s/\n", depth, "", entry->d_name);
            printdir(entry->d_name, depth+4);
        } else
            printf("%*s%s\n", depth, "", entry->d_name);
    }
    chdir("..");
    closedir(dp);
//#endif
}


/*
 args[1] : -c or -d or -h
 args[2] :输入文件名
 args[3] :输出文件名
 */
int main(int argc, char* argv[])
{
    //test
//    printf(argv[1],0);
    printdir(argv[1], 0);
//
//    char action = argv[1][1];
//    if(action == 'c')
//    {
//        printf("compress file or folder");
//        CompressDir(argv[2], argv[3],true);
//    }
//    else if (action == 'd'){
//        printf("decompress file or folder");
//        CompressDir(argv[2], argv[2],true);
//    }
//    else if (action == 'h') {
//        printf("*******************************\n");
//        printf("*******************************\n");
//        printf("*******************************\n");
//    }
    printf("ssssssssss");
    return 0;  
}


#endif