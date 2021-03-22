// includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

// defines
#define SLEEP 3000000
#define DEFAULT 0

/**
 * processes - Daemon
 * 1. create with fork().
 * 2. change it's dir to root, in order to release the filesystem.
 * 3. move it to a new session, so it will no be connected to starting process.
 * 4. close IO (stdin, stdout, stderr).
 * 5. optionaly - make some other way to interact with it (socket, signals, logs, etc.).
 * */

int main() {

    // create a child
    __pid_t pid = fork();

    if(pid == DEFAULT) {

        // move to root dir
        chdir("/");

        // move child to another session
        setsid();

        printf("starting daemon\n");

        // close IO channels
        close(stdout);
        close(stdin);
        close(stderr);

        // open log
        openlog("daemon", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "daemon started");
        usleep(SLEEP);
        syslog(LOG_NOTICE, "daemon work...");
        usleep(SLEEP);
        syslog(LOG_NOTICE, "daemon finished");
        
    } else {
        printf("daemon PID %d\n", pid);
    }

    return DEFAULT;
}
