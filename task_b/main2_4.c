// includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// defines
#define SLEEP 20

// main function
int main() {

    // run main2_1, main2_2 and main2_3 files
    system("./main2_1\n");
    system("./main2_2\n");
    system("./main2_3\n");
    sleep(SLEEP);

    // grep daemon from main2_3
    system("pstree | grep myDaemon /var/log/syslog");

    return 0;
}
