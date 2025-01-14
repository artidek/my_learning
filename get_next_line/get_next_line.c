/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:00:30 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/14 11:40:48 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	read_count = 1;
static char	*curline = NULL;


static int	move_offset(int fd)
{
	char	chr;
	ssize_t	r_count;

	r_count = 1;
	r_count = read_count;
	chr = '\0';
	while (r_count > 0)
	{
		r_count = read(fd, &chr, 1);
		if (chr == '\n')
			break ;
	}
	return (r_count);
}

static int	get_line(int fd, char **lineptr)
{
	int		i;
	char	chr;
	ssize_t	r_count;
	char	*temp;
	int		size;

	i = 0;
	r_count = 1;
	chr = '\0';
	size = BUFFER_SIZE + 1;
	alloc_str(size, &lineptr);
	temp = *lineptr;
	while (chr != '\n' && r_count > 0)
	{
		r_count = read(fd, &chr, 1);
		if (r_count > 0)
			temp[i] = chr;
		else
			break ;
		i++;
		if (i == size && chr != '\n')
			*lineptr = realloc_str(*lineptr, i);
		printf("%d %d\n", size , i);
	}
	temp[i] = '\0';
	return (r_count);
}

char	*get_next_line(int fd)
{
	char	*curline;
	int		len;

	len = 0;
	curline = NULL;
	if (fd < 0)
		return (NULL);
	if (read_count > 0)
	{
		read_count = get_line(fd, &curline);
		len = length(curline);
	}
	if (len == 0)
	{
		free(curline);
		return (NULL);
	}
	if (curline[len - 1] != '\n')
		read_count = move_offset(fd);
	return (curline);
}
