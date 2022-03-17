/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:48:55 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:48:56 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*cast_s;
	unsigned char		*cast_d;

	if (!src && !dst)
		return (NULL);
	if (src < dst)
	{
		cast_s = src + len - 1;
		cast_d = dst + len - 1;
		while (len--)
			*(cast_d--) = *(cast_s--);
	}
	else
	{
		cast_s = src;
		cast_d = dst;
		while (len--)
			*(cast_d++) = *(cast_s++);
	}
	return (dst);
}
