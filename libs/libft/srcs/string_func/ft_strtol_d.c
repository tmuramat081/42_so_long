/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:11:10 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/14 09:11:10 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_erange_long(unsigned long value, int cnv_dig, bool is_posi)
{
	if (is_posi == true
		&& ((unsigned long)LONG_MAX - cnv_dig) / 10 < value)
		return (true);
	else if (is_posi == false
		&& ((unsigned long)LONG_MAX + 1 - cnv_dig) / 10 < value)
		return (true);
	return (false);
}

static bool	is_space_and_sign(const char **nptr)
{
	bool	is_positive;

	is_positive = true;
	while (ft_isspace((int)**nptr))
		*nptr += 1;
	if (**nptr == '+')
		*nptr += 1;
	else if (**nptr == '-')
	{
		is_positive = false;
		*nptr += 1;
	}
	return (is_positive);
}

static long	output_value(long value, bool is_positive, bool is_erange)
{
	if (is_erange == true)
	{
		if (is_positive == true)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	else if (is_positive == false)
		value = 0 - value;
	return (value);
}

long	ft_strtol_d(const char *nptr, char **endp)
{
	unsigned long	value;
	int				cnv_dig;
	bool			is_positive;
	bool			is_erange;

	is_positive = is_space_and_sign(&nptr);
	value = 0;
	is_erange = 0;
	while (ft_isdigit(*nptr))
	{
		cnv_dig = *nptr - '0';
		if (is_erange_long(value, cnv_dig, is_positive))
		{
			errno = ERANGE;
			is_erange = true;
		}
		value = value * 10 + cnv_dig;
		nptr++;
	}
	if (endp)
		*endp = (char *)nptr;
	return (output_value(value, is_positive, is_erange));
}
