# Assignment 1
In this assignment we make two different programs called the parent and the child to make use of the fork() and exec() functions in C.

## Working:
1) The parent program is given two files that should be in the same directory as the program files.

2) The parent then creates another process through fork() called the child process.

3) The child process runs another program using the exec() function. What the child program does is check the given two files to find out if the files are similar or different.

4) The parent waits for the child to finish its execution before displaying the final output results onto the terminal.
