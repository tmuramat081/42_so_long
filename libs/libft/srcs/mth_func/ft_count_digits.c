/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:58:42 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 12:58:42 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits(long long int num, int radix)
{
	int	cnt;

	cnt = 0;
	if (radix == 10 && num < 0)
		cnt += 1;
	while (num)
	{
		num /= radix;
		cnt += 1;
	}
	return (cnt);
}
