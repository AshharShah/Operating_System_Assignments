#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    printf("Running Child Program!\n");
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);
    int file1 = open("file1.txt", O_RDWR);
    int file2 = open("file2.txt", O_RDWR);
    exit(0);
}