#include "libft.h"

size_t	ft_strlen_s(const char *c)
{
	size_t	cnt;

	if (!c)
		return (0);
	cnt = 0;
	while (*c++ != '\0')
		cnt += 1;
	return (cnt);
}