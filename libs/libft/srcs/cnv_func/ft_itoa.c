/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:48:20 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:48:22 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_number(long int num, char *str, size_t *i)
{
	if (num / 10)
		put_number(num / 10, str, i);
	else if (num < 0)
	{
		str[*i] = '-';
		*i += 1;
	}
	if (num < 0)
		num = 0 - num;
	str[*i] = num % 10 + '0';
	*i += 1;
	str[*i] = '\0';
}

static char	*count_digits(long int num)
{
	size_t	cnt;
	char	*str;

	if (num <= 0)
		cnt = 1;
	else
		cnt = 0;
	while (num)
	{
		num = num / 10;
		cnt++;
	}
	str = (char *) malloc(sizeof(char) * (cnt + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	long int	l_n;
	char		*str;
	size_t		index;

	index = 0;
	l_n = (long int)n;
	str = count_digits(l_n);
	if (str)
		put_number(l_n, str, &index);
	return (str);
}
