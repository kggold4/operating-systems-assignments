#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// print function that the procces print
void print(const char *text) {
    for(int i = 0; i < 20; i++) {
        printf("Hello from %s\n", text);
        usleep(1000000);
    }
}

// main function
int main() {

    // create child
    __pid_t pid = fork();
    
    if(pid == 0) {

        // create a grand child
        __pid_t pid = fork();
        if(pid == 0) {

            // grand child/process 2 print
            print("process 2");
        } else {
            
            // child/process 1 print
            print("process 1");
        }

    } else {

        // create another child
        __pid_t pid = fork();
        if(pid == 0) {

            // child 2 - process 1** print
            print("process 1**");
        } else {

            // parent/app print
            print("app");
        }
    }

    return 0;
}
