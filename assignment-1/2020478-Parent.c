#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    // Part 1, parent given 2 files as arguments which are displayed
    printf("The names of the files passed are:\n");
    for(int i = 1; i < argc; i++){
        printf("%s\n", argv[i]);
    }

    // Creating a child via the fork command
    int pid = fork();

    if(pid == -1){
        // what to do if failure to fork occurs (error handling)
        printf("Fork Failed!\n");
        exit(NULL);
    }
    else if(pid == 0){
        // code for the child
    }
    else{
        // code for the parent
    }

    exit(NULL);
}