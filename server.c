#include "minitalk.h"

//çalışıyor

void handler(int sig, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    static int swift = 0;
    static char bit = 0;

    if (sig == SIGUSR1)
    {
        bit = bit | (1 << swift);
    }

    swift++;
    if (swift == 8)
    {
        write(1, &bit, 1);
        if (bit == 0)
        {
            write(1, "\n", 1);
        }
        bit = 0;
        swift = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

int main()
{
    ft_putstr("Server PID: ");
    ft_putnbr(getpid());
    write(1, "\n", 1);

    struct sigaction sa;

    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
    {
        pause();
    }
    
}
