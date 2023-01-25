/**
 * \file genero.c
 * \brief System & process calls.
 * \author Brice W. K. <b.cicada@protonmail.com>
 * \version 0.1
 * \date 22 sept. 2022
 *
 * System & process calls in c file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid, child_pid;
    int status;

    pid = getpid();
    printf("PID du père: %d\n", pid);

    pid = fork();
    if (pid == 0) {
        // Processus fils
        child_pid = getpid();
        printf("PID du fils: %d\n", child_pid);
        printf("PID du père: %d\n", getppid());
        exit(child_pid % 10);
    } else {
        // Processus père
        printf("PID du fils: %d\n", pid);
        wait(&status);
        printf("Code de retour du fils: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
