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

	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_putnbr(int number)
{
	int count = 0;

	if (number < 0)
	{
		count += ft_putchar('-');
		number *= (-1);
	}
	if (number >= 10)
		ft_putnbr(number / 10);
	count += ft_putchar(number % 10 + '0');
	return (count);
}

int ft_puthex(int number)
{
	char *array = "0123456789abcdef";
	int count = 0;

	if (number >= 16)
		ft_puthex(number / 16);
	count += ft_putchar(array[number % 16]);
	return (count);
}

char *ft_strchr(char *string, int to_find)
{
	int i = 0;

	while(string[i] != '\0')
	{
		if (string[i] == (char)to_find)
			return ((char *)&string[i]);
		i++;
	}
	return (NULL);
}

int verify_and_call(const char id, va_list arg_box)
{
	int count = 0;

	if (id == 'd')
		count += ft_putnbr(va_arg(arg_box, int));
	if (id == 's')
		count += ft_putstr(va_arg(arg_box, char *));
	if (id == 'x')
		count += ft_puthex(va_arg(arg_box, unsigned int));
	return (count);
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
		if (format[i]== '%' && ft_strchr(types, format[i + 1]))
		{
			count += verify_and_call(format[i + 1], arg_box);
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(arg_box);
	return (count);
}












#include <stdio.h>

int main(void)
{
	int number = 123;
	char *string = "abcdef";
	char *empty_string = "";
	int hex = 42;

	ft_printf("int:  %d\n", number);
	ft_printf("string:  %s\n", string);
	ft_printf("empty string:  %s\n", empty_string);
	ft_printf("hexa:  %x\n", hex);
	printf("printf normal hexa:  %x\n", hex);

	
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