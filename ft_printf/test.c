#include "libftprintf.h"

int main()
{
	int val = 0;
	int val1 = 0;
	//char *null_str = NULL;

	val = ft_printf("%-c%-c%-4c%-11c", 'a', 'b', 'c', 'd');
	//val1 = printf("%s\n", "hello");
	printf ("%d\n", val);
	/*printf ("%d\n", val1);
	val = ft_printf("%.s\n", "hello");
	val1 = printf("%.s\n", "hello");
	printf ("%d\n", val);
	printf ("%d\n", val1);
	val = ft_printf("%.2s\n", "hello");
	val1 = printf("%.2s\n", "hello");
	printf ("%d\n", val);
	printf ("%d\n", val1);
	val = ft_printf("%.20s\n", "hello");
	val1 = printf("%.20s\n", "hello");
	printf ("%d\n", val);
	printf ("%d\n", val1);
	val = ft_printf("%2.20s\n", "hello");
	val1 = printf("%2.20s\n", "hello");
	printf ("%d\n", val);
	printf ("%d\n", val1);
	val = ft_printf("%25.20s\n", "hello");
	val1 = printf("%25.20s\n", "hello");
	printf ("%d\n", val);
	printf ("%d\n", val1);
	val = ft_printf("%05.20s\n", "hello");
	val1 = printf("%05.20s\n", "hello");
	printf ("%d\n", val);
	printf ("%d\n", val1);
	val = ft_printf("%025.20s\n", "hello");
	val1 = printf("%025.20s\n", "hello");
	printf ("%d\n", val);
	printf ("%d\n", val1);
	val = ft_printf("%-5.20s\n", "hello");
	val1 = printf("%-5.20s\n", "hello");
	printf ("%d\n", val);
	printf ("%d\n", val1);
	val = ft_printf("%-25.20s\n", "hello");
	val1 = printf("%-25.20s\n", "hello");
	printf ("%d\n", val);
	printf ("%d\n", val1);*/
	val1 = printf("%c%-c%-4c%-11c", 'a', 'b', 'c', 'd');
	printf("%d\n", val1);
}
