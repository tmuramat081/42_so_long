/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:47:50 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 23:26:04 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *p, size_t n)
{
	unsigned char	*cast_p;

	cast_p = (unsigned char *)p;
	ft_memset(cast_p, '\0', n);
}
