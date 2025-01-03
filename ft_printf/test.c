#include <stdio.h>

int main()
{
	printf("%025p\n", "hello");
	printf("%p\n", "hello");
	printf("%010p\n", NULL);
}
