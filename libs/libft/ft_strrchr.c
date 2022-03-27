/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:41 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:49:42 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cast_s;
	char	*p;

	p = NULL;
	cast_s = (char *)s;
	while (1)
	{
		if (*cast_s == (char)c)
			p = cast_s;
		if (*cast_s == '\0')
			break ;
		cast_s++;
	}
	return (p);
}
