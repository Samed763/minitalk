#include "minitalk.h"

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
       
    char c = (n % 10) + '0';
    write(1, &c, 1);
    
}
