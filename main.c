#include<stdio.h> // printf
#include<string.h> // memset strlen strcat
#include<ctype.h> // isalnum islower toupper
#include"pwd.h" // pwd
#include"file_exist.h" // file_exist
#include"memory.h" // memory_alloc memory_free
// argv[1]:c language header filename
int main(int argc,char*argv[]){
    if(argc!=2){
        printf("please input file name\n");
        return -1;
    }
    char* file_name=argv[1];
    printf("file name:%s\n",file_name);
    size_t file_name_byte_size=strlen(file_name)+1;
    for(size_t index=0;index+1<file_name_byte_size;++index){
        if(!(isalnum(file_name[index])||file_name[index]=='_'||file_name[index]=='.')){
            printf("file name error\n");
            return -2;
        }
    }
    char buffer[1024];
    memset(buffer,0,sizeof buffer);
    pwd(buffer,sizeof buffer);
    printf("pwd:%s\n",buffer);
    size_t file_path_byte_size=strlen(buffer)+strlen(file_name)+1;
    char* file_path=(char*)memory_alloc(file_path_byte_size);
    memset(file_path,0,file_path_byte_size);
    strcat(file_path,buffer);
    strcat(file_path,"/");
    strcat(file_path,file_name);
    printf("file path:%s\n",file_path);
    if(file_exist(file_path)){
        printf("file path exist!\n");
        memory_free((void*)file_path);
        return -3;
    }
    FILE* file=fopen(file_path,"w");
    if (file==NULL) {
        printf("file open error\n");
        memory_free((void*)file_path);
        return -4;
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
    fprintf(file,"#ifndef HF_%s\n#define HF_%s\n#ifdef __cplusplus\nextern \"C\"{\n#endif\n#ifdef __cplusplus\n}\n#endif\n#endif//!HF_%s",file_name_macro,file_name_macro,file_name_macro);
    fclose(file);
    memory_free((void*)file_path);
    return 0;
}
