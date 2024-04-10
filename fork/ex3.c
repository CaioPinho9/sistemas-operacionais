/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>

int main() {
    pid_t parent_pid = getpid();

    for (int i = 0; i < 2; i++) { // Create 2 child processes
        pid_t pid = fork();
        
        if (pid == 0) { // Child process
            printf("Processo %d filho de %d\n", getpid(), getppid());
            
            for (int j = 0; j < 2; j++) { // Each child creates 2 more children
                pid_t child_pid = fork();
                
                if (child_pid == 0) { // Grandchild process
                    printf("Processo %d filho de %d\n", getpid(), getppid());
                    return 0; // Grandchildren exit here
                } else {
                    wait(NULL); // Parent (i.e., the first child) waits for grandchildren
                }
            }
            return 0; // First-level children exit after creating their children
        }
    }

    while (wait(NULL) > 0); // The original parent waits for all first-level children to complete

    return 0;
}
