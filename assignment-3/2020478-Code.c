#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// our global variables that will be accessed and updated by the threads
double y;
int m_input;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// our multithreaded function that prints the required sum
void* sumMulti(void* arg){
    // static variable to tell us how much further do we need to run the loop
    static int m = 1;
    while(m <= m_input){
        // locks to ensure mutual exclusion
        pthread_mutex_lock(&lock);
        y = y + (((double)m-1.0)*((double)m-1.0))/5.0;
        m++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

// our single threaded function to calculate the required sum
double sumSingle(int m){
    double y = 0;
    for(int i = 1; i <=m; i++){
        y = y + (((double)i-1.0)*((double)i-1.0))/5.0;
    }
    return y;
}

int main(int argc, char* argv[]){
    // display the user an error if insufficent data provided
    if(argc <= 2){
        printf("Too Few Arguments!\n\n");
        // print the user with instruction on proper program execution
        printf("To Run The Program In Single Threaded Mode: ./<programName> 0 <m> \n");
        printf("E.g. ./program 0 2\n\n");
        printf("To Run The Program In Multi Threaded Mode: ./<programName> 1 <n> <m> \n");
        printf("E.g. ./program 0 3 4\n\n");
        exit(1);
    }
    if(atoi(argv[1]) == 1 && argc == 3){    // check for sufficent arguments for multi-thread execution
        printf("Error: Too Few Arguments To Run As Multi-Thread!\n\n");
        exit(1);
    }
    int doubleSingle = atoi(argv[1]);
    printf("\n");
    
    if(doubleSingle == 0){  // if single threaded just call the function
        m_input = atoi(argv[2]);
        printf("For The Value Of M: %d\n", m_input);
        printf("\nThe Value of Y: %lf\n\n", sumSingle(m_input));
    }
    else if(doubleSingle == 1){ // if multithreaded than create the required threads and join them
        int n = atoi(argv[2]);
        m_input = atoi(argv[3]);
        pthread_t threads[n];
        // initializing the threads to use the multithreaded summation function
        for(int i = 0; i < n; i++){
            pthread_create(&threads[i], NULL, sumMulti, NULL);
        }
        // waiting for all the threads to complete execution
        for(int i = 0; i < n; i++){
            pthread_join(threads[i], NULL);
        }
        // printing the value of Y
        printf("\nFor value of N = %d and value of M = %d \n", n, m_input);
        printf("The Value of Y: %lf\n\n", y);
    }
    exit(0);
}