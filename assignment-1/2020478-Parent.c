#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
    // Creating a child via the fork command and getting pid of both the child and parent
    int pidp = getpid();
    int pidc = fork();
    int stat;

    if(pidc == -1){
        // what to do if failure to fork occurs (error handling)
        printf("Fork Failed!\n");
        exit(1);
    }
    else if(pidc == 0){
        // code for the child
        execlp("./child", "child", argv[1], argv[2], NULL);
        // this line of code should not be printed during program execution
        // done only to find bugs
        printf("If you see this, there is a bug!\n");
    }
    else{
        // code for the parent
        wait(&stat);    // the parent should wait for child to finish
        // using macros to get exit code of the child
        int exitCode = WEXITSTATUS(stat);
        // displaying the output as stated
        printf("Starting Parent Process with PID : %d\n", pidp);
        printf("Filenames Recieved : %s %s\n", argv[1], argv[2]);
        printf("Child Process Created with PID : %d\n", pidc);
        // printing the error code along with the reason for the error code
        switch(exitCode){
            case 0:
                printf("ErrorCode %d : File1 and File2 Are Same!\n", exitCode);
                break;
            case 1:
                printf("ErrorCode %d : File1 and File2 Are Different!\n", exitCode);
                break;
            case 2:
                printf("ErrorCode %d : Error Opening Files / Same Filenames!\n", exitCode);
                break;
            default:
                printf("CHILD DID NOT RETURN A EXIT-CODE!\n");  // prompt the user of any errors
        }
    }
    exit(0);
}