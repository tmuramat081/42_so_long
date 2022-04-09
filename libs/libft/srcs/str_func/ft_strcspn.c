/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:53:00 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 12:53:00 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t	len;

	len = 0;
	while (*s1 != '\0')
	{
		if (ft_strchr(s2, *s1) != NULL)
			break ;
		s1++;
		len++;
	}
	return (len);
}
