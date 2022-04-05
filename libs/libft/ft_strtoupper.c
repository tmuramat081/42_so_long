#include "libft.h"

/* Convert a string to uppercase. */
void	ft_strtoupper(char *str)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}