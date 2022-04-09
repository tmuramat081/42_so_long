/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_lerp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:19:20 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 15:19:20 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector2	ft_vector_lerp(t_vector2 v1, t_vector2 v2, float t)
{
	t_vector2	ret;

	ret.x = (1.0f - t) * (float)v1.x + t * (float)v2.x;
	ret.y = (1.0f - t) * (float)v1.y + t * (float)v2.y;
	return (ret);
}
