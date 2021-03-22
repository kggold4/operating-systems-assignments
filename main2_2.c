#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 1000

char child_stack[STACK_SIZE + 1];

// print function that the procces print
void print(const char *text) {
    for(int i = 0; i < CYCLES; i++) {
        printf("Hello from %s\n", text);
        usleep(1000000);
    }
}

// runable function
int child(void *params) {
    print("child thread");
}

int main() {

    int result = clone(child, child_stack + STACK_SIZE, 0, 0);
    printf("clone results = %d\n", result);
    print("parent");

    return 0;
}
