#define _GNU_SOURCE

// includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// defines
#define SLEEP 20
#define DEFAULT 0

int main() {

    __pid_t pid1 = fork();
    if(!pid1) {
        execvp("./main2_1", NULL);
    }

    __pid_t pid2 = fork();
    if(!pid2) {
        execvp("./main2_2", NULL);
    }

    __pid_t pid3 = fork();
    if(!pid3) {
        execvp("./main2_3", NULL);
    }

    sleep(SLEEP);

    // grep daemon from main2_3
    system("pstree | grep myDaemon /var/log/syslog");

    return DEFAULT;
}
