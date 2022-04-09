/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:56:14 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/26 21:56:14 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* c, s, d, i, u, x, X */
const t_parrfunc	g_convert_func = {
	convert_into_char_and_print,
	convert_into_string,
	convert_into_decimal,
	convert_into_decimal,
	convert_into_address,
	convert_into_hexadecimal,
	convert_into_hexadecimal
};

/*If the syntax is wrong, print it as a character string. */
int	put_syntax_error(const char *parse_end)
{
	char	*parse_start;
	char	*str_err;
	int		ret_len;

	parse_start = (char *)parse_end;
	while (*parse_start != '%')
		parse_start--;
	str_err = ft_substr(parse_start, 0, parse_end - parse_start + 1);
	ret_len = ft_putstr_cnt(str_err);
	free(str_err);
	return (ret_len);
}

int	switch_conv_function(va_list *ap, t_finfo input, const char *parse_end)
{
	int	ret_len;

	if (input.specifier == SP_NONE)
		ret_len = put_syntax_error(parse_end);
	else if (input.specifier == PER_CT)
		ret_len = ft_putchar_cnt('%');
	else
		ret_len = g_convert_func[input.specifier](ap, input);
	return (ret_len);
}

/* Initialize the valiables (all flags, field width, precision, specifier). */
t_finfo	init_format_info(void)
{
	t_finfo	input;

	ft_memset(&input, 0, sizeof(t_finfo));
	input.width = EMPTY;
	input.precision = EMPTY;
	return (input);
}

int	print_arguments(const char *fmt, va_list *ap, size_t *i)
{
	t_finfo	input;
	int		ret_len;

	input = init_format_info();
	parse_flags(fmt, &input, i);
	parse_width(fmt, &input, ap, i);
	parse_precision(fmt, &input, ap, i);
	parse_specifier(fmt, &input, i);
	ret_len = switch_conv_function(ap, input, &fmt[*i]);
	return (ret_len);
}

int	ft_doprintf(const char *fmt, va_list *ap)
{
	size_t	i;
	int		ret;
	int		ret_len;

	i = 0;
	ret_len = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
			ret = ft_putchar_cnt(fmt[i]);
		else
		{
			i += 1;
			if (fmt[i] == '\0')
				return (ret_len);
			ret = print_arguments(fmt, ap, &i);
			if (ret == -1)
				return (-1);
		}
		ret_len += ret;
		i++;
	}
	return (ret_len);
}
