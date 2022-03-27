#include "libft.h"

char **ft_matrixdup(const char **src)
{
	char **dst;
	size_t m_len;
	size_t i;

	m_len = ft_matrixlen(src);
	dst = (char **)malloc(sizeof(char *) * (m_len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < m_len)
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
			ft_free_matrix(&dst);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
