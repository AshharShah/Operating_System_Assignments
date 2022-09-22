#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){

    // Part 1, parent given 2 files as arguments which are displayed
    printf("The names of the files passed are:\n");
    for(int i = 1; i < argc; i++){
        printf("%s\n", argv[i]);
    }

    // Creating a child via the forcleark command
    int pid = fork();
    int stat;

    if(pid == -1){
        // what to do if failure to fork occurs (error handling)
        printf("Fork Failed!\n");
        exit(0);
    }
    else if(pid == 0){
        // code for the child
        printf("In parents child block!\n");
        execlp("./child", "child", argv[1], argv[2], NULL);
        printf("If you see this, there is a bug!\n");
    }
    else{
        // code for the parent
        wait(&stat);
    }

    exit(0);
}