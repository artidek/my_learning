#include "get_next_line.h"

int main(void)
{
	char *res;

	res = get_next_line(0);
	while(res)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(0);
	}
	close(0);
	return (0);
}
