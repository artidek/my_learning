#include "get_next_line_bonus.h"

static d_list	*g_files = NULL;

static d_list	*move_list(int fd, d_list *temp)
{
	while (temp->fd != fd && temp->next)
			temp = temp->next;
	return (temp);
}

static void	update_files(int fd)
{
	d_list	*temp;
	d_list	*temp_next;

	temp = g_files;
	temp_next = NULL;
	if (!temp)
		return;
	temp = move_list(fd, temp);
	if (temp->next)
		temp_next = temp->next;
	clear_list(&(temp->t_list));
	if (!temp->t_list)
	{
		free(temp);
		temp = temp_next;
	}
	if (!temp)
	{
		g_files = NULL;
		return;
	}
}

static int	get_file(int fd, t_list **next_line)
{
	int		nw_fd;
	d_list	*temp;

	temp = g_files;
	if (!(temp->t_list))
		return (0);
	nw_fd = find_fd(temp);
	if (nw_fd < 0)
	{
		*next_line = init_list(fd);
		if (!next_line)
			return (0);
		while (temp->next)
			temp = temp->next;
		temp->fd = fd;
		temp->t_list = *next_line;
		temp->next = NULL;
		return (1);
	}
	temp = move_list(fd, temp);
	get_line(fd, &(temp->t_list));
	if (temp->t_list)
		*next_line = temp->t_list;
	return (1);
}

static d_list	*init_dlist(int fd, t_list **next_line)
{
	d_list	*new_dl;

	new_dl = malloc(sizeof(d_list));
	if (!new_dl)
		return (NULL);
	*next_line = init_list(fd);
	if (!*next_line)
	{
		free(new_dl);
		return (NULL);
	}
	new_dl->fd = fd;
	new_dl->t_list = *next_line;
	new_dl->next = NULL;
	return (new_dl);
}

char	*get_next_line(int fd)
{
	static t_list	*next_line = NULL;
	char			*curline;

	curline = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!g_files)
		g_files = init_dlist(fd, &next_line);
	if (!g_files)
		return (NULL);
	if (!get_file(fd, &next_line))
		return (NULL);
	extract_str(next_line, &curline);
	update_files(fd);
	if (!curline)
		return (NULL);
	if (!*curline)
	{
		free(curline);
		return (NULL);
	}
	return (curline);
}
