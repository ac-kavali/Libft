#include "libft.h"
#include <stdio.h>

int main(void)
{
	char **res = ft_split(NULL, ' ');
	if (!res)
		printf("✅ NULL input handled safely\n");
	else
		printf("❌ Error: should return NULL\n");
	return 0;
}
