/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:39 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:49:40 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	h_len;
	size_t	i;
	char	*hay_cast;

	hay_cast = (char *)haystack;
	n_len = ft_strlen(needle);
	h_len = ft_strlen(haystack);
	if (!n_len)
		return (hay_cast);
	else if (h_len < n_len || !len)
		return (NULL);
	i = 0;
	while (i + n_len <= len)
	{
		if (ft_strncmp(&hay_cast[i], needle, n_len) == 0)
			return (&hay_cast[i]);
		i++;
	}
	return (NULL);
}
