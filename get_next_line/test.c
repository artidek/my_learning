# include "get_next_line.h"

int main ()
{
	int i = 10;
	int fd;
	char *line = NULL;

	
	fd = open ("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	while (i-- > 0)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	free(line);
	close(fd);
	return (0);
}
