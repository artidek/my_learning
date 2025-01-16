/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:19:47 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/16 13:52:05 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	check_count(ssize_t r_count, int i, char **curline)
{
	char	*temp;

	temp = *curline;
	if (r_count < 0)
	{
		free(temp);
		return ;
	}
	if (i == 0)
	{
		free(temp);
		*curline = NULL;
		return ;
	}
	temp[i] = '\0';
}

static int	get_line(int fd, int size)
{
	int		i;
	char	chr;
	ssize_t	r_count;

	i = 0;
	r_count = 1;
	chr = '\0';
	while (chr != '\n' && r_count > 0)
	{
		r_count = read(fd, &chr, 1);
		if (r_count > 0)
			g_curline[i] = chr;
		else
			break ;
		i++;
		if (i == size - 1 && chr != '\n')
			size = mem_add(i);
	}
	check_count(r_count, i, &g_curline);
	if (r_count <= 0)
		return (r_count);
	return (r_count);
}

char	*get_next_line(int fd)
{
	int	size;
	int	read_count;

	size = 0;
	read_count = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (read_count > 0)
	{
		size = BUFFER_SIZE + 1;
		g_curline = malloc(size);
		if (!g_curline)
			return (NULL);
		read_count = get_line(fd, size);
	}
	else
		g_curline = NULL;
	if (read_count < 0)
		return (NULL);
	return (g_curline);
}
