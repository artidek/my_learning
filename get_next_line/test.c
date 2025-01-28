#include "get_next_line.h"
#include <fcntl.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                               } while (0)

int	main(void)
{
	int				ready;
	struct pollfd	*pfds;
	nfds_t			num_open_fds, nfds;
	char *files[7] = {"files/41_no_nl", "files/41_with_nl", "files/alternate_line_nl_no_nl", "files/empty", "files/multiple_line_no_nl", "files/big_line_no_nl","files/big_line_with_nl"};
	char *res;

	num_open_fds = nfds = 7;
	pfds = calloc(nfds, sizeof(struct pollfd));
	if (pfds == NULL)
		errExit("malloc");
	for (int j = 0; j < nfds; j++)
	{
		pfds[j].fd = open(files[j], O_RDONLY);
		if (pfds[j].fd < 0)
			errExit("open");;
		pfds[j].events = POLLIN;
	}
	while (num_open_fds > 0)
	{
		ready = poll(pfds, nfds, -1);
		if (ready == -1)
			errExit("poll");
		for (int j = 0; j < nfds; j++)
		{
			if (pfds[j].revents != 0)
			{
				if (pfds[j].revents & POLLIN)
				{
					res = get_next_line(pfds[j].fd);
					if (res)
					{
						printf("fd - %d %s\n", pfds[j].fd, res);
						free(res);
					}
					else
					{
						//printf("closing file %d\n", pfds[j].fd);
						if (close(pfds[j].fd) == -1)
							errExit("close");
						num_open_fds--;
					}
				}
			}
		}
	}
	free(pfds);
	return(0);
}
