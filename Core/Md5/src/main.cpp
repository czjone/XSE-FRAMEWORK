#ifndef ___MD5__GENERATE_TOOL
#define ___MD5__GENERATE_TOOL 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"

int main(int argc,char** arg){
    // unsigned char* str = (unsigned char*)"aaaaaaaaaaaaaa\n";
    //read file
    // std::vector<char> v;
    // if (FILE *fp = fopen("filename", "r"))
    // {
    //     char buf[1024];
    //     while (size_t len = fread(buf, 1, sizeof(buf), fp))
    //         v.insert(v.end(), buf, buf + len);
    //     fclose(fp);
    // }

    FILE * pFile;
    long lSize;
    char * buffer;
    size_t result;
    const char* path = arg[1];

    if (FILE *fp = fopen(path, "r"))
    {
      pFile = fopen ( path , "rb" );
      // if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

      // obtain file size:
      fseek (pFile , 0 , SEEK_END);
      lSize = ftell (pFile);
      rewind (pFile);

      // allocate memory to contain the whole file:
      buffer = (char*) malloc (sizeof(char)*lSize);
      // if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

      // copy the file into the buffer:
      result = fread (buffer,1,lSize,pFile);
      // if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

      MD5 md5;
      md5.GenerateMD5((unsigned char*)buffer,strlen((char*)buffer));
      printf("%s\n", md5.ToString().c_str());
      fclose(fp);
      free(buffer);
      
    }
    else{
        printf("not found file,file:%s\n",path);
    }
    return  1; 
}

#endif