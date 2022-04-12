/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff_timespec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:42:44 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:42:44 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_diff_timespec(const struct timespec *t1, const struct timespec *t2)
{
	double	ret_sec;

	ret_sec = t2->tv_sec - t1->tv_sec;
	ret_sec += (t2->tv_nsec - t1->tv_nsec) / 1000000000.0f;
	return (ret_sec);
}
