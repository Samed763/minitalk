#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_writed = 0;

void to_byte(int pid, char *str)
{
    for (int i = 0; i <= strlen(str); i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((str[i] >> j) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            while (!is_writed)
                ;
            is_writed = 0;
        }
    }
}

void yes_it_wirted(int sig)
{
    (void)sig;
    is_writed = 1;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        return 1;

    int pid = atoi(argv[1]);
    char *str = argv[2];

    struct sigaction sa;
    sa.sa_handler = yes_it_wirted;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    to_byte(pid, str);

    return 0;
}