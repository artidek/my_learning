#include "get_next_line_bonus.h"

int main(void)
{
	char *res;

	res = get_next_line(0);
	while(res)
	{
		printf("%s\n", res);
		free(res);
		res = get_next_line(0);
	}
	close(0);
	return (0);
}
