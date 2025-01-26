#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_putstr(char *str);
void	ft_putnbr(pid_t n);
int		ft_putchr(int c);
int		ft_strlen(char *str);

#endif