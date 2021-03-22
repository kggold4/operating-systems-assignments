#define _GNU_SOURCE

// includes
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// defines
#define SLEEP 1000000
#define STACK_SIZE 10000
#define CYCLES 1000
#define DEFAULT 0

char child_stack[STACK_SIZE + 1];

// print function that the procces print
void print(const char *text) {
    int i = DEFAULT;
    while(i < CYCLES) {
        printf("hello from %s\n", text);
        usleep(SLEEP);
        i++;
    }
}

// runable function
int child(void *params) { print("child thread"); }

// main
int main() {

    int result1 = clone(child, child_stack + STACK_SIZE, CLONE_PARENT, DEFAULT);
    printf("clone results1 = %d\n", result1);
    int result2 = clone(child, child_stack + STACK_SIZE, CLONE_PARENT, DEFAULT);
    printf("clone results2 = %d\n", result2);
    print("parent");

    return DEFAULT;
}   
