/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:47:40 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/12 22:15:46 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long int	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+')
		str += 1;
	else if (*str == '-')
	{
		sign = 0;
		str += 1;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (!sign)
		num = 0 - num;
	return (num);
}
