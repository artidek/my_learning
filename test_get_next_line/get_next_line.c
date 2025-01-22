/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:00:30 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/19 18:24:52 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clear_list(t_list **next_line)
{
	t_list	*tmp_lst;
	char	*cntnt;
	int		pos;
	int		i;
	char	*temp;

	i = 0;
	tmp_lst = check_nl(*next_line);
	if (!tmp_lst)
	{
		ft_lstclear(&(*next_line));
		*next_line = NULL;
		return ;
	}
	temp = malloc(BUFFER_SIZE + 1);
	pos = lststrlen(tmp_lst);
	cntnt = tmp_lst->content;
	cntnt += pos;
	while (*cntnt && temp)
		temp[i++] = *cntnt++;
	temp[i] = '\0';
	ft_lstclear(&(*next_line));
	*next_line = ft_lstnew(temp);
	free(temp);
}

static void	extract_str(t_list *temp, char **curline)
{
	int		len;
	int		i;
	int		j;
	char	*cntnt;

	if (!temp)
		return ;
	len = lststrlen(temp);
	i = 0;
	j = 0;
	*curline = malloc(len + 1);
	while (temp && *curline)
	{
		cntnt = temp->content;
		while (cntnt[i] && cntnt[i] != '\n')
			(*curline)[j++] = cntnt[i++];
		if (cntnt[i] == '\n')
			(*curline)[j] = cntnt[i];
		i = 0;
		temp = temp->next;
	}
	if (*curline)
		(*curline)[len] = '\0';
}

static void	get_line(int fd, t_list **next_line)
{
	int		read_count;
	char	*temp;
	t_list	*temp_lt;

	read_count = 0;
	temp = NULL;
	if (!*next_line)
		return ;
	temp_lt = *next_line;
	while (!check_nl(temp_lt))
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return ;
		read_count = read(fd, temp, BUFFER_SIZE);
		if (read_count <= 0)
		{
			free(temp);
			return ;
		}
		temp[read_count] = '\0';
		ft_lstadd_back(&(*next_line), ft_lstnew(temp));
		temp_lt = temp_lt->next;
		free(temp);
	}
}

static t_list	*init_list(int fd)
{
	t_list	*int_lst;
	char	*temp;
	int		read_count;

	int_lst = NULL;
	temp = NULL;
	read_count = 0;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	read_count = read(fd, temp, BUFFER_SIZE);
	if (read_count <= 0)
	{
		free(temp);
		return (NULL);
	}
	temp[read_count] = '\0';
	int_lst = ft_lstnew(temp);
	free(temp);
	return (int_lst);
}

char	*get_next_line(int fd)
{
	static t_list	*next_line = NULL;
	char			*curline;

	curline = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!next_line)
		next_line = init_list(fd);
	if (!next_line)
		return (NULL);
	get_line(fd, &next_line);
	extract_str(next_line, &curline);
	clear_list(&next_line);
	if (!curline)
		return (NULL);
	if (!*curline)
	{
		free(curline);
		return (NULL);
	}
	return (curline);
}
