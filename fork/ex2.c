/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 


int main()
{
    for (int i = 0; i< 4; i++) {
        int id = fork();
        int pid = getpid();
        if (id > 0) {
            printf("Processo pai %d criou %d\n", pid, id);
        } else {
            printf("Processo filho %d\n", pid);
            break;
        }
        wait();
    }
    
    return 0;
}
