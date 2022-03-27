#include "libft.h"

void ft_free_matrix(char ***src)
{
	size_t i;

	i = 0;
	while ((*src)[i])
	{
		free((*src)[i]);
		(*src)[i] = NULL;
		i++;
	}
	free(*src);
	*src = NULL;
}