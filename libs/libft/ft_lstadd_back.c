/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:48:23 by tmuramat          #+#    #+#             */
/*   Updated: 2022/02/25 19:48:25 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prev;

	if (!lst)
		return ;
	else if (!*lst)
	{
		*lst = new;
		return ;
	}
	prev = ft_lstlast(*lst);
	prev->next = new;
}
