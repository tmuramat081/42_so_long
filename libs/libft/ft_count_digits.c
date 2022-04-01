#include "libft.h"

int	ft_count_digits(int num, int radix)
{
	int cnt;

	cnt = 0;
	while (num)
	{
		num /= radix;
		cnt += 1;
	}
	return (cnt);
}
