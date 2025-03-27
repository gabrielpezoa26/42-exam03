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
	long num;

	num = (long)nbr;
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
	int count = 0;
	char *array = "0123456789abcdef";

	if (nbr >= 16)
		ft_puthex(nbr / 16);
	count += ft_putchar(array[nbr % 16]);
	return (count);
}

char *ft_strchr(char *string, int potato)
{
	int i = 0;

	while(string[i] != '\0')
	{
		if (string[i] == (char)potato)
			return ((char *)&string[i]);
		i++;
	}
	return (NULL);
}

int verify_apply(const char id, va_list argbox)
{
	int count = 0;

	if (id == 'd')
		count += ft_putnbr(va_arg(argbox, int));
	if (id == 's')
		count += ft_putstr(va_arg(argbox, char *));
	if (id == 'x')
		count += ft_puthex(va_arg(argbox, unsigned int));
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list argbox;
	char *types = "dsx";
	int count = 0;
	int i = 0;

	va_start(argbox, format);
	while(format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr(types, format[i + 1]))
		{
			count += verify_apply(format[i + 1], argbox);
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(argbox);
	return (count);
}

//teste
int main()
{
	int number = 123;
	char *string = "abcdef";
	int hex = 42;
	int hex2 = 10;

	ft_printf("%d\n", number);
	ft_printf("%s\n", string);
	ft_printf("%x\n", hex);
	ft_printf("%x\n", hex2);
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