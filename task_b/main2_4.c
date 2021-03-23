// includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



// main function
int main() {

    

    execv("./main2_1 & ./main2_2 & ./main2_3", NULL);
    printf("run\n");

    // char *args1[] = {"./main2_1", NULL};
    // char *args2[] = {"./main2_2", NULL};
    // char *args3[] = {"./main2_3", NULL};
    // char **args[] = {args1, args2, args3};

    // int i = 0;
    // while(i < 3) {

    //     __pid_t pid = fork();

    //     if(pid != 0) {
    //         printf("./main2_%d\n", i + 1);
    //         execv(args[i][0], args[i]);
    //     }
    //     i++;
    // }
    
    return 0;
}