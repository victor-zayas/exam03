
#include<unistd.h>
#include<stdarg.h>

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	ft_putnbr(int nb, int base, int *len)
{
	char *hex = "0123456789abdcef";

	if (nb < 0)
	{
		nb *= -1;
		*len += write(1, "-", 1);
	}
	if (nb >= base)
	{
		ft_putnbr((nb / base), base, len);
		ft_putnbr((nb % base), base, len);
	}
	else
		*len += write(1, &hex[nb], 1);


}

int	ft_printf(const char *format, ...)
{
	int	len = 0;
	va_list	ptr;

	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%' && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				ft_putnbr(va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				ft_putnbr(va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(ptr);
	return(len);
}

int	main(void)
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}