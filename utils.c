#include "minitalk.h"

int	ft_putchr(int c)
{
	if (write(1, &c, 1) == -1)
		exit(EXIT_FAILURE);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchr(str[i]);
		i++;
	}
}

void	ft_putnbr(pid_t n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	ft_putchr(c);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
