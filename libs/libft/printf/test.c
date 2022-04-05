#include <stdio.h>
#include "ft_snprintf.c"

int main ()
{
	char str[50];

	ft_snprintf(str, sizeof(str), "%d%d", 41, 42);
	printf("%s\n", str);
	return (0);

}

