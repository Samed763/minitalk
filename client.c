/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sadinc@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:33:53 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/04 03:28:32 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			g_is_writed = 0;

static int	ft_atoi(char *str)
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

void	to_byte(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
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

void	yes_it_wrote(int sig)
{
	(void)sig;
	g_is_writed = 1;
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_putstr("Invalid PID\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, yes_it_wrote);
	while (argv[2][i])
		to_byte(pid, argv[2][i++]);
	to_byte(pid, '\0');
	return (0);
}
