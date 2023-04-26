#include<stdio.h> // printf
#include<string.h> // memset strlen strcat
#include<ctype.h> // isalnum islower toupper
#include"pwd.h" // pwd
#include"file_exist.h" // file_exist
#include"memory.h" // memory_alloc memory_free
extern bool checkHeaderFilename(char const* header_filename);
// argv[1]:c language header filename
int main(int argc,char*argv[]){
    if(argc!=2){
        printf("please input file name\n");
        return -1;
    }
    char* file_name=argv[1];
    if(!checkHeaderFilename(file_name)){
        printf("header filename error\n");
        return -2;
    }
// TODO
    if(file_exist(file_path)){
        printf("file path exist!\n");
        memory_free((void*)file_path);
        return -4;
    }
    printf("buffer length:%d\n",buffer_length);
    size_t file_path_byte_size=strlen(buffer)+strlen(file_name)+2;
    printf("file path byte size:%d\n",file_path_byte_size);
    char* file_path=(char*)memory_alloc(file_path_byte_size);
    memset(file_path,0,file_path_byte_size);
    strcat(file_path,buffer);
    strcat(file_path,"/");
    strcat(file_path,file_name);
    printf("file path:%s\n",file_path);
    FILE* file=fopen(file_path,"w");
    if (file==NULL) {
        printf("file open error\n");
        memory_free((void*)file_path);
        return -5;
    }
    char* file_name_macro=file_name;
    for(size_t index=0;index+1<file_name_byte_size;++index){
        if(islower(file_name[index])){
            file_name_macro[index]=toupper(file_name[index]);
        }else if(file_name[index]=='.'){
            file_name_macro[index]='_';
        }else{
            file_name_macro[index]=file_name[index];
        }
    }
    printf("file name macro:%s\n",file_name_macro);
    fprintf(file,"#ifndef __HF_%s__\n",file_name_macro);
    fprintf(file,"#define __HF_%s__\n",file_name_macro);
    fprintf(file,"/* include header file */\n\n");
    fprintf(file,"#ifdef __cplusplus\n    extern \"C\"{\n#endif // __cplusplus\n");
    fprintf(file,"/* decl public interface */\n\n");
    fprintf(file,"#ifdef __cplusplus\n    }\n#endif // __cplusplus\n");
    fprintf(file,"#endif // !__HF_%s__\n",file_name_macro);
    fclose(file);
    memory_free((void*)file_path);
    return 0;
}
bool checkHeaderFilename(char const* header_filename){
    if(header_filename==NULL){
        return false;
    }
    for(size_t index=0;index+1<strlen(header_filename);++index){
        if(!(isalnum(file_name[index])||file_name[index]=='_'||file_name[index]=='.')){
            return false;
        }
    }
    return true;
}
