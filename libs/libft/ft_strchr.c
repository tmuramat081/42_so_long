/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:15 by tmuramat          #+#    #+#             */
/*   Updated: 2022/03/19 12:12:51 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cast_s;

	cast_s = (char *)s;
	while (1)
	{
		if (*cast_s == (char)c)
			return (cast_s);
		if (*cast_s == '\0')
			break ;
		cast_s++;
	}
	return (NULL);
}
