/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:00:30 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/30 01:06:05 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(int fd, char **r_lines);
static void	append_line(int fd, char **r_lines, int size);
static void	return_line(int fd, char **current_line, char **r_lines);
static int	form_line( char **r_line, char *buffer, int r_count, int size);

char	*get_next_line(int fd)
{
	static char	*r_lines[FD_MAX];
	char		*current_line;
	int			size;

	size = BUFFER_SIZE;
	current_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!r_lines[fd])
		size = get_line(fd, r_lines);
	if (r_lines[fd] && !ft_strchr(r_lines[fd], '\n'))
		append_line(fd, r_lines, size);
	if (r_lines[fd])
		return_line(fd, &current_line, r_lines);
	return (current_line);
}

static int	get_line(int fd, char **r_lines)
{
	char	*temp;
	int		r_count;

	r_count = 0;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	r_count = read(fd, temp, BUFFER_SIZE);
	if (r_count <= 0)
	{
		free(temp);
		return (0);
	}
	temp[r_count] = '\0';
	r_lines[fd] = ft_strdup(temp);
	free(temp);
	return (BUFFER_SIZE - r_count);
}

static void	append_line(int fd, char **r_lines, int size)
{
	char	*temp_r;
	int		r_count;

	size = BUFFER_SIZE - ft_strlen(r_lines[fd]);
	temp_r = malloc(BUFFER_SIZE + 1);
	if (!temp_r)
		return ;
	r_count = 1;
	while (r_count > 0 && r_lines[fd])
	{
		r_count = read(fd, temp_r, BUFFER_SIZE);
		if (r_count == 0)
		{
			free(temp_r);
			return ;
		}
		temp_r[r_count] = '\0';
		size = form_line(&r_lines[fd], temp_r, r_count, size);
		if (ft_strchr(temp_r, '\n') || !r_lines[fd])
			break ;
	}
	free(temp_r);
}

static void	return_line(int fd, char **current_line, char **r_lines)
{
	char	*nl;
	char	*cp_lines;

	nl = ft_strchr(r_lines[fd], '\n');
	cp_lines = NULL;
	if (nl && *(nl + 1))
	{
		cp_lines = ft_strdup(nl + 1);
		if (!cp_lines)
			return ;
		*(nl + 1) = '\0';
	}
	*current_line = ft_strdup(r_lines[fd]);
	free(r_lines[fd]);
	r_lines[fd] = cp_lines;
}

static int	form_line( char **r_line, char *buffer, int r_count, int size)
{
	int	len;
	char	*temp;

	if (size - r_count <= r_count)
	{
		len = ft_strlen(*r_line);
		size = (len + r_count) * 2;
		realloc_line(r_line, buffer, size);
		if (!*r_line)
			return (-1);
		return (size - (len + r_count));
	}
	temp = *r_line;
	while(*temp)
		temp++;
	while (*buffer)
		*temp++ = *buffer++;
	*temp = '\0';
	return (size - r_count);
}
