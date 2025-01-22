#include "get_next_line_bonus.h"

static t_files	*g_descriptors = NULL;

static void	init_t_files(int fd, t_files **list)
{
	*list = malloc(sizeof(t_files));
	if (!*list)
		return;
	(*list)->t_list = init_list(fd);
	if (!((*list)->t_list))
	{
		free(*list);
		*list = NULL;
		return;
	}
	(*list)->fd = fd;
	(*list)->next = g_descriptors;
	g_descriptors = *list;
}

static void	clear_t_files(int fd)
{
	t_files	*temp;
	t_files	*prev;

	temp = g_descriptors;
	prev = NULL;
	if (!g_descriptors)
		return;
	while (temp && temp->fd != fd)
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
		return;
	clear_list(&(temp->t_list));
	if (!(temp->t_list))
	{
		if (temp->next && prev)
			prev->next = temp->next;
		free(temp);
		temp = NULL;
		if (!prev)
			g_descriptors = NULL;
		return;
	}
}

static void	get_file(int fd)
{
	t_files	*temp;
	t_files *prev;

	temp = g_descriptors;
	prev = NULL;
	if (!temp)
		return;
	while(temp->next && temp->fd != fd)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp->fd != fd)
	{
		if (!prev)
			prev = temp;
		printf("t_list pointer %p fd %d\n", temp->t_list, fd);
		fflush(stdout);
		temp = temp->next;
		init_t_files(fd, &(temp));
		if (!temp)
		{
			if (prev)
				prev->next = NULL;
			return;
		}
		if (temp && !(temp->t_list))
		{
			free(temp);
			prev->next = NULL;
			return;
		}
		prev->next = temp;
		return;
	}
	if (temp)
		get_line(fd, &(temp->t_list));
}

static void	extract_line(int fd, char **curline)
{
	t_files	*temp;

	temp = g_descriptors;
	if (!temp)
		return;
	while(temp && temp->fd != fd)
		temp = temp->next;
	if (!temp)
		return;
	if(temp->t_list)
		extract_str(temp->t_list, &*curline);
}

char	*get_next_line(int fd)
{
	char			*curline;

	curline = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!g_descriptors)
		init_t_files(fd, &g_descriptors);
	if (!g_descriptors)
		return (NULL);
	get_file(fd);
	extract_line(fd, &curline);
	clear_t_files(fd);
	if (!curline)
		return (NULL);
	if (!*curline)
	{
		free(curline);
		return (NULL);
	}
	return (curline);
}
