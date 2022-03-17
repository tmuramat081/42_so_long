/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:43 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:49:44 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (s1[j] && ft_strchr(set, s1[j]) && i < j)
		j--;
	j = j + 1;
	dest = (char *) malloc(sizeof(char) * (j - i + 1));
	if (dest)
		ft_strlcpy(dest, &s1[i], j - i + 1);
	return (dest);
}
