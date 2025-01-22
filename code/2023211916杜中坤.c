#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXN 105

void copy_file(char file1[],char file2[])
{
    char command[MAXN]="";
    snprintf(command, sizeof(command),"cp %s %s",file1,file2);
    if(system(command))
        printf("Error copying file\n");
    else
        printf("copy successfully\n");
}

void delete_file(char file1[])
{
    char command[MAXN]="";
    snprintf(command, sizeof(command),"rm %s",file1);
    if(system(command))
        printf("Error deleting file\n");
    else
        printf("delete successfully\n");
}

void compress_file(char file1[],char file2[])
{
    char command[MAXN]="";
    snprintf(command, sizeof(command),"tar -czf %s %s",file2,file1);
    if(system(command))
        printf("Error compressing file\n");
    else
        printf("compress successfully\n");
}

void decompress_file(char file1[],char file2[])
{
    char command[MAXN]="";
    snprintf(command, sizeof(command), "tar -xzf %s -C %s",file1,file2);
    if(system(command))
        printf("Error decompressing file\n");
    else
        printf("decompress successfully\n");
}
void print_usage()
{
    printf("Please input your command:\n");
    printf("1. COPY: cp <source file> <target file>\n");
    printf("2. DELETE: rm <filename>\n");
    printf("3. COMPRESS: compress <filename> <compressed package name>\n");
    printf("4. DECOMPRESS: decompress <compressed package name> <target directory>\n");
    printf("5. EXIT: exit\n");
}
int main()
{
    char str[MAXN];
    char file1[MAXN],file2[MAXN];
    print_usage();
    while(1)
    {
        printf("Please input your command:\n");
        scanf("%s",str);
        if(!strcmp(str,"cp"))
        {
            scanf("%s %s",file1,file2);
            copy_file(file1,file2);
        }
        else
        if(!strcmp(str,"rm"))
        {
            scanf("%s",file1);
            delete_file(file1);
        }
        else
        if(!strcmp(str,"compress"))
        {
            scanf("%s %s",file1,file2);
            compress_file(file1,file2);
        }
        else 
        if(!strcmp(str,"decompress"))
        {
            scanf("%s %s",file1,file2);
            decompress_file(file1,file2);
        }
        else 
        if(!strcmp(str,"exit"))
        {
            printf("program has exit\n");
            break;
        }
        else
        {
            printf("Error\n");
        }
    }
    return 0;
}


