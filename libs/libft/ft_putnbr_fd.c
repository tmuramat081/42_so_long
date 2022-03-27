/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:06 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:49:07 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	l_n;
	char		c;

	l_n = (long int)n;
	if (l_n < 0)
	{
		ft_putchar_fd('-', fd);
		l_n = l_n * -1;
	}
	if (l_n / 10)
		ft_putnbr_fd(l_n / 10, fd);
	c = l_n % 10 + '0';
	ft_putchar_fd(c, fd);
}
