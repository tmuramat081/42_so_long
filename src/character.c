# include "so_long.h"

void	character_lstiter(t_clist *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(&lst->pos);
		lst = lst->next;
	}
}


t_clist	*character_lstlast(t_clist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	character_lstadd_back(t_clist **lst, t_clist *new_character)
{
	t_clist *prev;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new_character;
		return ;
	}
	prev = character_lstlast(*lst);
	prev->next = new_character;
}

t_clist	*character_lstnew(t_vector2 pos)
{
	t_clist *new_character;

	new_character = malloc(sizeof(t_clist));
	if (!new_character)
		return (NULL);
	*new_character = (t_clist){};
	new_character->pos = pos;
	new_character->next = NULL;
	return (new_character);
 }

void set_new_character(t_clist **lst, t_vector2 pos)
{
	t_clist *new_character;

	new_character = character_lstnew(pos);
	character_lstadd_back(lst, new_character);
}

