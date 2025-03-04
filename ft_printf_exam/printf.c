/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:33:13 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/03/04 13:38:58 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>  //teste
#include <string.h> //teste

static int ft_strchr(const char *str, int mangoloko)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&c);
		i++;
	}
	return (0);
}

static int ft_putchar(char c)
{
	write(1, &c, 1);
}

static int ft_putstr(char *str)
{
	int i;

	i = 0;
	printed = 0;
	while (str[i] != '\0')
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

static int	ft_print_adress(unsigned long n)
{
	char	*hex_digits_lower;
	int		result;

	result = 0;
	hex_digits_lower = "0123456789abcdef";
	if (n >= 16)
		result += ft_print_adress(n / 16);
	result += ft_putchar(hex_digits_lower[n % 16]);
	return (result);
}

static int	verify_type(const char *id, va_list *arg_box)
{
	int result;

	result = 0;
	if (id == 's')
		result += ft_putstr(arg_box);
	if (id == 'd')
		result += ft_putnbr(arg_box);
	if (id == 'x')
		result += ft_printhex(arg_box);
	return (result);
}

int ft_printf(const char *, ... )
{
	
}

int main(void)
{
	char *teste = "abcdef";

	ft_printf("%s\n", teste);
}

/*
Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but 
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$
*/