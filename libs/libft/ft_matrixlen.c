#include "libft.h"

size_t	ft_matrixlen(const char **src)
{
	size_t len;

	if (src == NULL)
		return (0);
	len = 0;
	while (src[len])
		len++;
	return (len);
}