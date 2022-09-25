#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    //printf("Running Child Program!\n");
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);

    // return the exit code of 2, error opening files/same file name
    if(argv[1] == argv[2]){
        exit(2);
    }
    // variables to store the characters read line by line
    char f1;
    char f2;
    // opening the files using the open() method
    int file1 = open(argv[1], O_RDWR);
    int file2 = open(argv[2], O_RDWR);
    int f1size = 0;
    int f2size = 0;
    int notequal = 0;

    while((read(file1, &f1, 1) == 1) && (read(file2, &f2, 1) == 1)){
        //printf("%c\n",f1);
        //printf("%c\n",f2);
        f1size++;
        f2size++;
        // if any character has not matched than the files are not equal
        if(f1 != f2){
            notequal = 1;
            //exit(1);
        }
    }
    // if file 1 has remaining characters then the files are not equal
    if((read(file1, &f1, 1) == 1)){
        printf("%s has more characters\n",argv[1]);
        f1size = f1size + 2;
        while(read(file1, &f1, 1) == 1){
            f1size++;
        }
        printf("f1size : %d\n", f1size);
        printf("f2size : %d\n", f2size);
        exit(1);
    }
    // else if file 2 has remaining characters then the files are not equal
    else if((read(file2, &f2, 1) == 1)){
        printf("%s has more characters\n",argv[2]);
        f2size++;
        while(read(file2, &f2, 1) == 1){
            f2size++;
        }
        printf("f1size : %d\n", f1size);
        printf("f2size : %d\n", f2size);
        exit(1);
    }
    if(notequal == 1){
        printf("f1size : %d\n", f1size);
        printf("f2size : %d\n", f2size);
        exit(1);
    }
    // if all checks for unequal turn out false then files are equal
    //printf("Files are Equal\n");
    printf("f1size : %d\n", f1size);
    printf("f2size : %d\n", f2size);
    exit(0);
}