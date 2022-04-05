#include "libft.h"

int	ft_count_digits(long long int num, int radix)
{
	int cnt;

	cnt = 0;
	if (radix == 10 && num < 0)
		cnt += 1;
	while (num)
	{
		num /= radix;
		cnt += 1;
	}
	return (cnt);
}
