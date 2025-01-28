/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:00:30 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/28 20:12:07 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	get_line(int fd, char **r_lines);
static void	append_line(int fd, char **r_lines);
static void	return_line(int fd, char **current_line, char **r_lines);

char	*get_next_line(int fd)
{
	static char	*r_lines[FD_MAX];
	char		*current_line;

	current_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!r_lines[fd])
		get_line(fd, r_lines);
	if (r_lines[fd] && !ft_strchr(r_lines[fd], '\n'))
		append_line(fd, r_lines);
	if (r_lines[fd])
		return_line(fd, &current_line, r_lines);
	return (current_line);
}

static void	get_line(int fd, char **r_lines)
{
	char	*temp;
	int		r_count;

	r_count = 0;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return ;
	r_count = read(fd, temp, BUFFER_SIZE);
	if (r_count <= 0)
	{
		free(temp);
		return ;
	}
	temp[r_count] = '\0';
	r_lines[fd] = ft_strdup(temp);
	free(temp);
}

static void	append_line(int fd, char **r_lines)
{
	char	*temp_r;
	char	*cp_line;
	int		r_count;

	r_count = 1;
	while (r_count > 0 && r_lines[fd])
	{
		temp_r = malloc(BUFFER_SIZE + 1);
		if (!temp_r)
			return ;
		r_count = read(fd, temp_r, BUFFER_SIZE);
		if (r_count == 0)
		{
			free(temp_r);
			return ;
		}
		temp_r[r_count] = '\0';
		cp_line = ft_strjoin(r_lines[fd], temp_r);
		free(r_lines[fd]);
		r_lines[fd] = cp_line;
		if (ft_strchr(temp_r, '\n'))
			r_count = 0;
		free(temp_r);
	}
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
