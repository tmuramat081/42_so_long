/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:48:48 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:48:49 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *buff, int ch, size_t n)
{
	unsigned char	*buff_cast;

	buff_cast = (unsigned char *)buff;
	while (n--)
	{
		if (*buff_cast == (unsigned char)ch)
			return ((void *)buff_cast);
		buff_cast++;
	}
	return (NULL);
}
