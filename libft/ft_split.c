/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:12 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:49:13 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**count_split(const char *str, char c)
{
	size_t	i;
	size_t	cnt;
	char	**str_sp;

	i = 0;
	cnt = 1;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i + 1] == c)
			cnt += 1;
		i++;
	}
	if (str[i - 1] == c)
		cnt += 1;
	str_sp = (char **)malloc(sizeof(char *) * (cnt + 1));
	return (str_sp);
}

static void	free_split(char **str_sp)
{
	size_t	i;

	i = 0;
	while (str_sp[i] != NULL)
	{
		free(str_sp[i]);
		i++;
	}
	free(str_sp);
}

static char	*get_split(const char *src, int begin, int end)
{
	char	*dst;
	size_t	len;

	len = (end - begin + 1) + 1;
	dst = (char *)malloc (sizeof(char) * len);
	if (!dst)
		return (NULL);
	*dst = 0;
	ft_strlcpy(dst, &src[begin], len);
	return (dst);
}

static int	parse_split(const char *str, char c, char **str_sp)
{
	size_t	i;
	size_t	pre_i;

	i = 0;
	pre_i = 0;
	while (1)
	{
		if (str[pre_i] == c)
			pre_i += 1;
		else if ((str[i] == c || str[i] == '\0') && pre_i < i)
		{
			*str_sp = get_split(str, pre_i, i - 1);
			if (!*str_sp++)
			{
				free_split(str_sp);
				return (0);
			}
			pre_i = i + 1;
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
	*str_sp = NULL;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**str_sp;

	if (!str)
		return (NULL);
	str_sp = count_split(str, c);
	if (!str_sp)
		return (NULL);
	if (!parse_split(str, c, str_sp))
		return (NULL);
	return (str_sp);
}
