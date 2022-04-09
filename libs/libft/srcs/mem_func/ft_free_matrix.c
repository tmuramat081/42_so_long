/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:00:33 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 13:00:33 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char ***src)
{
	size_t	i;

	i = 0;
	while ((*src)[i])
	{
		free((*src)[i]);
		(*src)[i] = NULL;
		i++;
	}
	free(*src);
	*src = NULL;
}
