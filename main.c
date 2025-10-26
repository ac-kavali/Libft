#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *s = "  \t\nHello World\n\t  ";
    char *trim = ft_strtrim(s, " \n\t");
    printf("Result: \"%s\"\n", trim);
    return (0);
}
