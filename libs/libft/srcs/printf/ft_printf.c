/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:41:29 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/22 22:41:29 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	ret = ft_doprintf(fmt, &ap);
	va_end (ap);
	return (ret);
}
