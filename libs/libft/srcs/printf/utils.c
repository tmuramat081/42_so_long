/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:11:59 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/23 16:11:59 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Suport for base(radix), unsigned long long. */
char	*ft_itoa_base(unsigned long long value, char *buff, int base)
{
	char	*offset;

	if (!buff)
		return (NULL);
	offset = buff;
	if (0 > (signed long long)value && base == 10)
		value = -value;
	if (value / base)
		offset = ft_itoa_base(value / base, offset, base);
	*offset = (value % base) + '0';
	if (*offset > '9')
		*offset += 'a' - '9' - 1;
	*++offset = '\0';
	return (offset);
}

int	ft_putchar_cnt(int c)
{
	write(1, &c, 1);
	return (1);
}

/* Return number of characters. */
int	ft_putstr_cnt(char *str)
{
	int		ret_len;
	size_t	i;

	if (!str)
		return (0);
	ret_len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		ret_len += ft_putchar_cnt(str[i]);
		i++;
	}
	return (ret_len);
}

/* If the augument is null, return 0. */
int	ft_strlen_s(const char *c)
{
	size_t	cnt;

	if (!c)
		return (0);
	cnt = 0;
	while (*c++ != '\0')
		cnt += 1;
	return (cnt);
}
