/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_mul.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:20:21 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 15:20:21 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector2	ft_vector_mul(t_vector2 v1, float t)
{
	t_vector2	ret;

	ret.x = (float)v1.x * t;
	ret.y = (float)v1.y * t;
	return (ret);
}
