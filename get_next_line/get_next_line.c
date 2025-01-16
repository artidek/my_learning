/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:00:30 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/16 17:23:40 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*g_curline = NULL;

static int	mem_add(int size)
{
	char	*temp;

	temp = realloc_str(g_curline, size);
	free(g_curline);
	g_curline = malloc((size * 2) + 1);
	if (!g_curline)
		return (0);
	ft_memset(g_curline, 0, (size * 2) + 1);
	ft_memcpy(g_curline, temp, size);
	free(temp);
	return ((size * 2) + 1);
}

static void	extract_line(char **retstr, int i, ssize_t r_count)
{
	int	line_len;

	line_len = 0;
	if (i + 1 < r_count)
		line_len = (int)r_count - ((int)r_count - i);
	else
		line_len = r_count;
	*retstr = malloc(line_len + 1);
	if (!*retstr)
		return ;
	ft_memcpy(*retstr, g_curline, line_len);
}

void	check_count(ssize_t r_count, int i, char **curline)
{
	char	*temp;

	temp = *curline;
	if (r_count < 0)
	{
		free(temp);
		return ;
	}
	if (r_count == 0)
	{
		free(temp);
		*curline = NULL;
		return ;
	}
	temp[i] = '\0';
}

static int	get_line(int fd, int size, char **retstr)
{
	int		i;
	ssize_t	r_count;

	i = 0;
	r_count = 1;
	while (r_count > 0)
		r_count = read(fd, g_curline, BUFFER_SIZE);
	check_count(r_count, i, &g_curline);
	if (r_count <= 0)
		return (r_count);
	return (r_count);
}

char	*get_next_line(int fd)
{
	int		read_count;
	int		size;
	char	*retstr;

	read_count = 1;
	size = 0;
	retstr = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (read_count > 0)
	{
		size = BUFFER_SIZE + 1;
		g_curline = malloc(size);
		if (!g_curline)
			return (NULL);
		read_count = get_line(fd, size, &retstr);
	}
	else
		g_curline = NULL;
	if (read_count < 0)
		return (NULL);
	return (retstr);
}
