/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** pipe
*/

#include "train.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void redirect_io(int inputfd[2], int outputfd[2])
{
    dup2(inputfd[0], 0);
    dup2(outputfd[1], 1);
    close(inputfd[1]);
    close(outputfd[0]);
}

void play_simulation(network_t *net)
{
    int trash = open("/dev/null", O_WRONLY);
    int pipe1fd[2];
    int pipe2fd[2];
    int stat;
    int pid;

    pipe(pipe1fd);
    pipe(pipe2fd);
    pid = fork();
    if (pid == 0) {
        dup2(trash, 2);
        redirect_io(pipe1fd, pipe2fd);
        execl("./n4s", "./n4s", NULL);
    } else {
        redirect_io(pipe2fd, pipe1fd);
        evaluate_network(net);
        waitpid(pid, &stat, 0);
        close(trash);
    }
}