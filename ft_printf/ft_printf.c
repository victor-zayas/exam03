
#include<unistd.h>
#include<stdarg.h>

void ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	ft_putnbr(long nbr, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
	{
		ft_putnbr((nbr / base), base, len);
		ft_putnbr((nbr % base), base, len);
	}
	else
		*len += write(1, &hex[nbr], 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	format;
	int	len = 0;

	va_start(format, str);
	while (*str)
	{
		if (*str == '%' && ((*(str + 1) == 's') || (*(str + 1) == 'd') || (*(str + 1) == 'x')))
		{
			str++;
			if (*str == 's')
				ft_putstr(va_arg(format, char *), &len);
			else if (*str == 'd')
				ft_putnbr(va_arg(format, int), 10, &len);
			else if (*str == 'x')
				ft_putnbr(va_arg(format, unsigned int), 16, &len);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(format);
	return(len);
}

/* int	main(void)
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
} */
