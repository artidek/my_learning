# include "get_next_line.h"
#include <string.h>

int main (void)
{
	char	*res;
	int		fd;

	fd = open("big_line_no_nl", O_RDONLY);
	res = get_next_line(fd);
	while(res)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
}
