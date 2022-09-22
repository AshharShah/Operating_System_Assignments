#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    printf("The names of the files passed are:\n");
    for(int i = 1; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    exit(1);
}