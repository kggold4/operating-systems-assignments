// includes
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// defines
#define CYCLES 20
#define SLEEP 1000000
#define DEFAULT 0

// print function that the procces print
void print(const char *text) {
    int i = DEFAULT;
    while(i < CYCLES) {
        printf("hello from %s\n", text);
        usleep(SLEEP);
        i++;
    }
}

// main function
int main() {

    // create child
    __pid_t pid = fork();
    
    if(pid == DEFAULT) {

        // create a grand child
        __pid_t pid = fork();
        if(pid == DEFAULT) {

            // grand child/process 2 print
            print("process 2");
        } else {
            
            // child/process 1 print
            print("process 1");
        }
    }
    return DEFAULT;
}
