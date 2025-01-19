# include "get_next_line.h"

int main (void)
{
	char	*res;
	int		fd;

	fd = open("alternate_line_nl_no_nl", O_RDONLY);
	res = get_next_line(fd);
	while(res)
	{
		printf("%s\n", res);
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
}
