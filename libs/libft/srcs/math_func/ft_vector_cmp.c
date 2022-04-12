/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:17:22 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 15:17:22 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_vector_cmp(t_vector2 v1, t_vector2 v2)
{
	if (v1.x == v2.x && v1.y == v2.y)
		return (true);
	return (false);
}
