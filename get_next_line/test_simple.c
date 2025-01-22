# include "get_next_line_bonus.h"
#include <string.h>

int main (void)
{
	char	*res;
	int		fd;

	fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
	res = get_next_line(fd);
	while(res)
	{
		//printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
}
