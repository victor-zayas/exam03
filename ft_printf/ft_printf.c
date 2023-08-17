
#include<stdarg.h>
#include<unistd.h>

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_digt(long nb, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if (nb < 0)
	{
		nb *= -1;
		*len += write(1, "-", 1);
	}
	if (nb >= base)
	{
		put_digt((nb / base), base, len);
		put_digt((nb % base), base, len);
	}
	else
		*len += write(1, &hex[nb], 1);
}

int ft_printf(const char *format, ... )
{
	int len = 0;
	va_list ptr;

	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%' && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_digt(va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				put_digt(va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return(va_end(ptr), len);
}

/* int	main(void)
{
	ft_printf("%s\n", "hola");
	ft_printf("%d\n", 16);
	ft_printf("%x\n", 141317);
}*/