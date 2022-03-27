#include "libft.h"

size_t ft_strcspn(const char *s1, const char *s2)
{
	size_t len;

	len = 0;
	while (*s1 != '\0')
	{
		if (ft_strchr(s2, *s1) != NULL)
			break ;
		s1++;
		len++;
	}
	return (len);
}
