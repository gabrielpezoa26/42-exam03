#include <unistd.h>
#include <stdarg.h>

int ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_putnbr(int nbr)
{
	int count = 0;

	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= (-1);
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}

int ft_puthex(int nbr)
{
	int co
}