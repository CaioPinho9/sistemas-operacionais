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
    printf("Hello World\n");
    
    int id = fork();
    printf("%d\n", id);
    
    if (id == 0) {
        printf("Child\n");
    } else {
        printf("Parent\n");
    }
    
    return 0;
}
