# include "get_next_line.h"

int main ()
{
	int fd;
	char *res;

	//printf("fucking here");
	fd = open("41_no_nl", O_RDONLY);
	res = get_next_line(fd);
	while (res)
	{
		printf("%s\n", res);
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
	return (0);
}
