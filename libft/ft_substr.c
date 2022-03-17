/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:45 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:49:46 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;
	size_t	d_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start + len)
		d_len = s_len - start;
	else
		d_len = len;
	if (!len || s_len <= start)
	{	
		dest = ft_strdup("");
		return (dest);
	}
	dest = malloc(sizeof(char) * (d_len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, &s[start], d_len + 1);
	return (dest);
}
