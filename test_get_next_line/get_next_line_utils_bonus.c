/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:49:03 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/20 21:52:50 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	lststrlen(t_list *next_line)
{
	int		len;
	int		i;
	char	*contnt;
	int	a = 0;

	len = 0;
	i = 0;
	while (next_line)
	{
		contnt = next_line->content;
		while (contnt[i] != '\n' && contnt[i])
		{
			i++;
			len++;
		}
		if (contnt[i] == '\n')
		{
			len++;
			break ;
		}
		a++;
		next_line = next_line->next;
		i = 0;
	}
	return (len);
}

t_list	*check_nl(t_list *next_line)
{
	int		pos;
	char	*cntnt;

	pos = 0;
	if (!next_line)
		return (NULL);
	while (next_line)
	{
		cntnt = next_line->content;
		while(cntnt[pos] != '\n' && cntnt[pos])
			pos++;
		if (cntnt[pos] == '\n')
		{
			pos++;
			return (next_line);
		}
		pos = 0;
		next_line = next_line->next;
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_list	*ft_lstnew(char *cont)
{
	t_list	*new_lst;
	int	len;
	char	*cntnt;
	int	i;

	len = 0;
	cntnt = NULL;
	i = 0;
	new_lst = (t_list *)malloc(sizeof(t_list) * 1);
	if (new_lst == NULL)
		return (NULL);
	while (cont[len])
		len++;
	cntnt = malloc(len + 1);
	if (!cntnt)
		return (NULL);
	while (cont[i])
	{
		cntnt[i] = cont[i];
		i++;
	}
	cntnt[len] = '\0';
	new_lst->content = cntnt;
	new_lst->next = NULL;
	return (new_lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		if ((*lst)->content)
			free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}


void	clear_list(t_list **next_line)
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

void	extract_str(t_list *temp, char **curline)
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

void	get_line(int fd, t_list **next_line)
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

t_list	*init_list(int fd)
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

int	find_fd(d_list *files)
{
	int fnd_fd;

	fnd_fd = -1;
	while (fnd_fd < 0 && files)
	{
		fnd_fd = files->fd;
		files = files->next;
	}
	return (fnd_fd);
}
