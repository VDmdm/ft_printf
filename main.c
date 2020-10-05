#include "includes/ft_printf.h"
#include "srcs/libft/includes/libft.h"
#include <stdio.h>

int        main()
{
    int    ret1, ret2;

    ret2 = 0;
    //ret1 = printf("%.-2s\n", 0);
    //printf("\n");
    ret2 = ft_printf("%.-2s\n", 0);
    printf("\n%d - %d\n", ret1, ret2);
    return (0);
}