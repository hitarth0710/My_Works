#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    /* fork a child process */
    pid = fork();

    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0) { /* child process */
        printf("I am the child, my pid is %d\n", getpid());
    }
    else { /* parent process */
        printf("I am the parent, my pid is %d\n", getpid());
    }

    return 0;
}