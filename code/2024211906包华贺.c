#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void copy_file(const char *src_file, const char *dest_file) {
    char command[256];
    
    snprintf(command, sizeof(command), "cp %s %s", src_file, dest_file);
    
    if (system(command) == -1) {
        printf("文件复制失败");
    } else {
        printf("文件 %s 复制到 %s 成功\n", src_file, dest_file);
    }
}


void delete_file(const char *filename) {
    char command[256];
    snprintf(command, sizeof(command), "rm -f %s", filename);
    if (system(command) == -1) {
        perror("文件删除失败");
    } else {
        printf("文件 %s 删除成功\n", filename);
    }
}


void compress_file(const char *filename) {
    char command[256];
    snprintf(command, sizeof(command), "tar -czf %s.tar.gz %s", filename, filename);
    if (system(command) == -1) {
        perror("文件压缩失败");
    } else {
        printf("文件 %s 压缩成功\n", filename);
    }
}


void decompress_file(const char *filename) {
    char command[256];
    snprintf(command, sizeof(command), "tar -xzf %s", filename);
    if (system(command) == -1) {
        perror("文件解压失败");
    } else {
        printf("文件 %s 解压成功\n", filename);
    }
}
int main(int argc, char *argv[]) {
int option = argv[1];
const char *filename = argv[2];

switch (option) {
    case 1:
        if (argc < 4) {
            printf("复制文件时需要提供目标文件名\n");
            return 1;
        }
        const char *dest_file = argv[3];
        copy_file(filename, dest_file);
        break;
    case 2:
        delete_file(filename);
        break;
    case 3:
        compress_file(filename);
        break;
    case 4:
        decompress_file(filename);
        break;
    default:
        printf("无效的操作选项，请选择 1、2、3 或 4\n");
}

return 0;
}
