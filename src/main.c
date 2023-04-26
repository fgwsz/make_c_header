#include<stdbool.h> // bool
#include<stdio.h> // printf FILE fopen fclose fprintf
#include<string.h> // strlen
#include<ctype.h> // isalnum
#include<stddef.h> // size_t
extern bool checkHeaderFilename(char const* header_filename);
extern bool fileExist(char const* file_path);
// argv[1]:c language header filename
int main(int argc,char*argv[]){
    if(argc!=2){
        printf("please input file name\n");
        return -1;
    }
    char* header_filename=argv[1];
    if(!checkHeaderFilename(header_filename)){
        printf("header filename error\n");
        return -2;
    }
    if(fileExist(header_filename)){
        printf("header file exist!\n");
        return -3;
    }
    FILE* stream=fopen(header_filename,"w");
    if (stream==NULL) {
        printf("header file open error\n");
        return -4;
    }
    char* header_filename_macro=header_filename;
    size_t header_filename_length=strlen(header_filename);
    for(size_t index=0;index<header_filename_length;++index){
        if(islower(header_filename[index])){
            header_filename_macro[index]=toupper(header_filename[index]);
        }else if(header_filename[index]=='.'){
            header_filename_macro[index]='_';
        }else{
            header_filename_macro[index]=header_filename[index];
        }
    }
    fprintf(stream,"#ifndef __HF_%s__\n",header_filename_macro);
    fprintf(stream,"#define __HF_%s__\n",header_filename_macro);
    fprintf(stream,"/* include header file */\n");
    fprintf(stream,"\n");
    fprintf(stream,"#ifdef __cplusplus\n");
    fprintf(stream,"    extern \"C\"{\n");
    fprintf(stream,"#endif // __cplusplus\n");
    fprintf(stream,"/* decl public interface */\n");
    fprintf(stream,"\n");
    fprintf(stream,"#ifdef __cplusplus\n");
    fprintf(stream,"    }\n");
    fprintf(stream,"#endif // __cplusplus\n");
    fprintf(stream,"#endif // !__HF_%s__\n",header_filename_macro);
    fclose(stream);
    return 0;
}
bool checkHeaderFilename(char const* header_filename){
    if(header_filename==NULL||header_filename[0]=='\0'||isdigit(header_filename[0])){
        return false;
    }
    for(size_t index=0;index+1<strlen(header_filename);++index){
        if(!(isalnum(header_filename[index])||header_filename[index]=='_'||header_filename[index]=='.')){
            return false;
        }
    }
    return true;
}
bool fileExist(char const* file_path){
    FILE* stream=fopen(file_path,"r");
    if(stream==NULL){
        return false;
    }
    fclose(stream);
    return true;
}
