/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:08:27 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:08:27 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_lstclear(t_clist **character)
{
	t_clist	*tmp;

	if (!character)
		return ;
	while (*character)
	{
		tmp = (*character)->next;
		free(*character);
		*character = tmp;
	}
}

void	character_lstadd_back(t_clist **lst, t_clist *new_character)
{
	t_clist	*prev;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new_character;
		return ;
	}
	prev = *lst;
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = new_character;
}

void	character_lstnew(t_clist **lst, t_vector2 pos, t_typ type)
{
	t_clist	*new_character;

	new_character = malloc(sizeof(t_clist));
	if (!new_character)
		put_error_and_exit(ERR_FILE_READ);
	*new_character = (t_clist){};
	new_character->pos = pos;
	new_character->type = type;
	new_character->next = NULL;
	character_lstadd_back(lst, new_character);
}
