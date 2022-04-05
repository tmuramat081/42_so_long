#include "ft_snprintf.h"
#include "libft.h"

int	switch_conv_func(char *buff, size_t *left, const char fmt, va_list *ap)
{
	if (fmt == 'c')
		return (charcpy_buff(buff, left, va_arg(*ap, int)));
	else if (fmt == 's')
		return (strcpy_buff(buff, left, va_arg(*ap, void *)));
	else if (fmt == 'd' || fmt == 'i')
		return (convert_decimal_to_buff(buff, left, ap, true));
	else if (fmt == 'u')
		return (convert_decimal_to_buff(buff, left, ap, false));
	else if (fmt == 'x')
		return (convert_hexadecimal_to_buff(buff, left, ap, false));
	else if (fmt == 'X')
		return (convert_hexadecimal_to_buff(buff, left, ap, true));
	else if (fmt == '%')
		return (charcpy_buff(buff, left, '%'));
	return (-1);
}

int ft_dosnprintf(char *buff, size_t left, const char *fmt, va_list *ap)
{
	int	size;
	int	ret_len;

	size = 0;
	ret_len = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			size = charcpy_buff(buff, &left, *fmt);
		else
		{
			fmt += 1;
			size = switch_conv_func(buff, &left, *fmt, ap);
		}
		if (size == -1)
			return (-1);
		buff += size;
		ret_len += size;
		fmt++;
	}
	*buff = '\0';
	return (ret_len);
}

int ft_snprintf(char *buff, size_t n, const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	ret = ft_dosnprintf(buff, n, fmt, &ap);
	va_end (ap);
	return (ret);
}
