/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:26 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:49:27 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;

	if (!dstsize)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize < d_len)
		return (s_len + dstsize);
	ft_strlcpy (dst + d_len, src, dstsize - d_len);
	return (d_len + s_len);
}
