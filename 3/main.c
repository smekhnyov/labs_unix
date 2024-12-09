#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_processes>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Number of processes must be a positive integer.\n");
        return 1;
    }
    printf("Parent process: PID = %d\n", getpid());

    int processes_left = n;
    
    pid_t pid;

    while (processes_left > 0) {
        pid = fork();

        if (pid < 0) {
            perror("Error during process creation");
            return 1;
        } else if (pid == 0) {
            printf("Process: PID = %d, PPID = %d\n", getpid(), getppid());

            processes_left--;
            if (processes_left > 0) {
                continue;
            } else {
                break;
            }
        } else {
            wait(NULL);
            break;
        }
    }
    return 0;
}
