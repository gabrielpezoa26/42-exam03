/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kartoffellll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:32:13 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/03/05 20:10:36 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

/*-----------LIBFT-----------*/
int ft_putchar(int c)
{
	write(1, &c, 1);
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

int	ft_putnbr(int n)
{
	long	num;
	int		counter;

	num = (long)n;
	counter = 0;
	if (num < 0)
	{
		counter += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		counter += ft_putnbr(num / 10);
	counter += ft_putchar(num % 10 + '0');
	return (counter);
}

int ft_printhex(unsigned long n)
{
	char *hex_array = "0123456789abcdef";
	int counter = 0;
	if (n >= 16)
		ft_printhex(n / 16);
	counter += ft_putchar(hex_array[n % 16]);
	// write(1, &hex_array[n % 16]);
	return (counter);
}

char *ft_strchr(const char *str, int character)
{
	int i;

	while(str[i]!= '\0')
	{
		if (str[i] == (unsigned char)character)
			return ((char *)&str[i]);
		i++;
	}
}

/*-----------PRINTF-----------*/

void ft_verify_type()
{
	
}

int ft_printf(const char *format, ...);

int main(void);