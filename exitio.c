/**
 * \file exitio.c
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
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <mot>\n", argv[0]);
        return 1;
    }

    pid_t pid;
    int status;
    int fd;

    pid = getpid();
    printf("PID du père: %d\n", pid);

    pid = fork();
    if (pid == 0) {
        // Processus fils
        printf("PID du fils: %d\n", getpid());
        close(2); // Ferme le descripteur 2 (stderr)
        fd = mkstemp("/tmp/proc-exercise");
        dup2(fd, 1);
        printf("Numéro de descripteur du fichier: %d\n", fd);
        execlp(argv[1], argv[1], NULL);
    } else {
        // Processus père
        wait(&status);
        printf("That's All Folks!\n");
    }

    return 0;
}
