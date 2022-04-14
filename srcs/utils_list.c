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

void	character_lstnew(t_game *game, t_vector2 pos, t_typ type)
{
	t_clist	*new_character;

	new_character = malloc(sizeof(t_clist));
	if (!new_character)
		handle_process_error(game, ERR_MEMORY);
	*new_character = (t_clist){};
	new_character->pos = pos;
	new_character->type = type;
	new_character->next = NULL;
	character_lstadd_back(&game->character, new_character);
}

size_t	char_lstiter(t_game *game, void (*f)(t_game *, t_clist *), t_typ type)
{
	size_t	cnt;
	t_clist	*character;

	character = game->character;
	cnt = 0;
	while (character)
	{
		if (f && (character->type & type))
		{
			f(game, character);
			cnt += 1;
		}
		character = character->next;
	}
	return (cnt);
}
