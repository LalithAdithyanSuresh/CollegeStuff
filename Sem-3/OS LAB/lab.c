#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {
        printf("This is the child process\n");
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    } else {
        printf("This is the parent process\n");
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
        printf("Child process complete\n");
    }

    return 0;
}