/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:17 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:49:18 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*p;
	size_t	len;

	len = ft_strlen(src);
	p = (char *) malloc (sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, src, len + 1);
	return (p);
}
