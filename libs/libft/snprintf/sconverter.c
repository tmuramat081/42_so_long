#include "ft_snprintf.h"
#include "libft.h"

int	copy_string_to_buff(char *buff, size_t *left, void *str)
{
	if (!str)
		return (strcpy_buff(buff, left, "(null)"));
	return (strcpy_buff(buff, left, str));
}

int	convert_decimal_to_buff(char *buff, size_t *left, va_list *ap, bool is_signed)
{
	unsigned long long	value;
	char 				tmp[12];
	int					ret_len;

	if (is_signed == false)
		value = va_arg(*ap, unsigned int);
	else
		value = va_arg(*ap, int);
	ft_uitoa_base(value, tmp, 10);
	ret_len = strcpy_buff(buff, left, tmp);
	return (ret_len);
}

int convert_hexadecimal_to_buff(char *buff, size_t *left, va_list *ap, bool is_large)
{
	unsigned long long	value;
	int					ret_len;
	char				tmp[12];

	value = va_arg(*ap, unsigned int);
	ft_uitoa_base(value, tmp, 16);
	ret_len = strcpy_buff(buff, left, tmp);
	if (is_large == true)
		ft_strtoupper(buff);
	return (ret_len);
}
