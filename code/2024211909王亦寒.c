#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void cp(char *source,char *target){
    char x[100]="\0";
    strcat(x,"cp ");
    strcat(x,source);
    strcat(x," ");
    strcat(x,target);
    if(system(x)!=0){
        printf("复制文件时出错\n");
    }else{
        printf("复制文件成功\n");
    }
}

void rm(char *filename){
    char x[100]="\0";
    strcat(x,"rm ");
    strcat(x,filename);
    if(system(x)!=0){
        printf("删除文件时出错\n");
    }else{
        printf("删除文件成功\n");
    }
}

void compress(char *file,char *compressed){
    char x[100]="\0";
    strcat(x,"tar -czvf ");
    strcat(x,compressed);
    strcat(x," ");
    strcat(x,file);
    if(system(x)!=0){
        printf("压缩文件时出错\n");
    }else{
        printf("压缩文件成功\n");
    }
}

void decompress(char *compressed,char *file){
    char x[100]="\0";
    strcat(x,"tar -xzvf ");
    strcat(x,compressed);
    strcat(x," ");
    strcat(x,file);
    if(system(x)!=0){
        printf("解压文件时出错\n");
    }else{
        printf("解压文件成功\n");
    }
}

int main()
{
    char command[100]="\0";

    printf("Please input your command:\n");
    printf("1. COPY: cp <source file> <target file>\n");
    printf("2. DELETE: rm <filename>\n");
    printf("3. COMPRESS: compress <filename> <compressed package name>\n");
    printf("4. DECOMPRESS: decompress <compressed package name> <target directory>\n");
    printf("5. EXIT: exit\n");
    printf("Please input your command:)\n");

    while(1){
        scanf("%s",command);
        if(strcmp(command,"exit")==0){
            return 0;
        }else if(strcmp(command,"cp")==0){
            char source[100],target[100];
            scanf("%s %s",source,target);
            cp(source,target);
        }else if(strcmp(command,"rm")==0){
            char filename[100];
            scanf("%s",filename);
            rm(filename);
        }else if(strcmp(command,"compress")==0){
            char file[100],compressed[100];
            scanf("%s %s",file,compressed);
            compress(file,compressed);
        }else if(strcmp(command,"decompress")==0){
            char compressed[100],file[100];
            scanf("%s %s",compressed,file);
            decompress(compressed,file);
        }else{
            printf("Error Command\n");
        }
    }
}

