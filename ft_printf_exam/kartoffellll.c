/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kartoffellll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:32:13 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/03/07 07:40:33 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

/*-----------LIBFT-----------*/
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

int ft_puthex(unsigned long n)
{
	char *hex_array = "0123456789abcdef";
	int counter = 0;
	if (n >= 16)
		ft_puthex(n / 16);
	counter += ft_putchar(hex_array[n % 16]);
	return (counter);
}

char *ft_strchr(const char *str, int character)
{
	int i = 0;

	while(str[i]!= '\0')
	{
		if (str[i] == (unsigned char)character)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

/*-----------PRINTF-----------*/

int ft_verify_type(const char id, va_list arg_box)
{
	int result = 0;

	if (id == 'd')
		result += ft_putnbr(va_arg(arg_box, int));
	if (id == 's')
		result += ft_putstr(va_arg(arg_box, char *));
	if (id == 'x')
		result += ft_puthex(va_arg(arg_box, unsigned int));
	return (result);
}

int ft_printf(const char *format, ...)
{
	char *types = "dsx";
	va_list arg_box;
	int i = 0;
	int count = 0;

	va_start(arg_box, format);
	while(format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr(types, format[i + 1]))
		{
			count += ft_verify_type(format[i + 1], arg_box);
		}
		i++;
	}
	va_end(arg_box);
	return (count);
}

int main(void)
{
	char *mango = "12345";

	ft_printf("%s", mango);
}
