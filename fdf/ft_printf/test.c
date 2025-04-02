#include "libftprintf.h"

int main()
{
	printf("%d\n", ft_printf("%0#20x\n", 12435784));
	printf("%d\n", printf("%0#20x\n", 12435784));
}
