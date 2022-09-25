#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    printf("Running Child Program!\n");
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);

    // return the exit code of 2, error opening files/same file name
    if(argv[1] == argv[2]){
        exit(2);
    }

    char f1;
    char f2;
    int file1 = open(argv[1], O_RDWR);
    int file2 = open(argv[2], O_RDWR);

    while((read(file1, &f1, 1) == 1) && (read(file2, &f2, 1) == 1)){
        printf("%c\n",f1);
        printf("%c\n",f2);
        // if any character has not matched than the files are not equal
        if(f1 != f2){
            exit(1);
        }
    }
    // if file 1 has remaining characters then the files are not equal
    if((read(file1, &f1, 1) == 1) && (read(file2, &f2, 1) == 0)){
        printf("%s has more characters\n",argv[1]);
        exit(1);
    }
    // else if file 2 has remaining characters then the files are not equal
    else if((read(file1, &f1, 1) == 0) && (read(file2, &f2, 1) == 1)){
        printf("%s has more characters\n",argv[2]);
        exit(1);
    }
    // if all checks for unequal turn out false then files are equal
    printf("equal");
    exit(0);
}