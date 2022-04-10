# include "so_long.h"

bool	is_hit_character(t_vector2 my_pos, t_vector2 my_next, t_clist *you)
{
	t_vector2 you_next;

	while(you)
	{ 
		you_next = ft_vector_add(you->pos, you->vector);
		if (ft_vector_cmp(my_pos, you->pos) == false && ft_vector_cmp(my_next, you_next) == true)
		{
			return (true);
		}
		you = you->next;
	}
	return (false);
}

void	character_lstiter(t_clist *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(&lst);
		lst = lst->next;
	}
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
	prev = *lst;
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = new_character;
}

void character_lstnew(t_clist **lst, t_vector2 pos, t_type type)
{
	t_clist *new_character;

	new_character = malloc(sizeof(t_clist));
	if (!new_character)
		return ;
	*new_character = (t_clist){};
	new_character->pos = pos;
	new_character->type = type;
	new_character->next = NULL;
	character_lstadd_back(lst, new_character);
}

