/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:54:00 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 12:54:00 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_snprintf.h"
#include "libft.h"

/* Suport for base(radix), unsigned long long. */
char	*ft_uitoa_base(unsigned long long value, char *buff, int base)
{
	char	*offset;

	if (!buff)
		return (NULL);
	offset = buff;
	if (0 > (signed long long)value && base == 10)
	{
		*offset++ = '-';
		value = -value;
	}
	if (value / base)
		offset = ft_uitoa_base(value / base, offset, base);
	*offset = (value % base) + '0';
	if (*offset > '9')
		*offset += 'a' - '9' - 1;
	*++offset = '\0';
	return (offset);
}

int	charcpy_buff(char *buff, size_t *left, int c)
{
	if (c == '\0')
		return (0);
	if (*left > 1)
	{
		*buff = c;
		*left -= 1;
	}
	return (1);
}

int	strcpy_buff(char *buff, size_t *left, char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (*left > 1)
		{
			*buff++ = str[i];
			*left -= 1;
		}
		i++;
	}
	return (i);
}
