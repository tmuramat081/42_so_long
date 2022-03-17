/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:48:58 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 23:25:52 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t len)
{
	void	*ret;

	ret = p;
	while (len--)
	{
		*(unsigned char *)p = (unsigned char)c;
		p++;
	}
	return (ret);
}
