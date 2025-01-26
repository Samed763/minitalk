#include "minitalk.h"

int		g_is_writed = 0;

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

void	to_byte(int pid, char *str)
{
	int	i;
	int	arglen;

	arglen = ft_strlen(str);
	i = 0;
	while (i < 8)
	{
		if ((str[i] >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		while (!g_is_writed)
			;
		g_is_writed = 0;
		i++;
	}
}

void	yes_it_wirted(int sig)
{
	g_is_writed = 1;
	if (sig == SIGUSR2)
		ft_putstr("Char Writed Successfully\n");
	else if (sig == SIGUSR1)
		ft_putstr("Byte Received\n");
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					i;
	char				*str;
	struct sigaction	sa;

	i = 0;
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		ft_putstr("Invalid PID\n");
	*str = argv[2];
	sa.sa_handler = yes_it_wirted;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (str[i])
		to_byte(pid, str);
	return (0);
}
