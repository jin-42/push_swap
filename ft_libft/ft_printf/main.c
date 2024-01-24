#include "ft_printf.h"
#include <stdio.h>
# include <limits.h> 

int	main(void)
{
 printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
}
