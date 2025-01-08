/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:00:30 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/09 00:12:07 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd)
{
	static char	*buf;
	ssize_t		read_count;
	int			count;

	read_count = 1;
	count = 0;
	buf = ft_calloc(sizeof(char), sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (count < BUFFER_SIZE && read_count > 0)
	{
		read_count = read(fd, &buf[count], 1);
		if (buf[count] == '\n')
			break ;
		if (read_count < 0)
			return (NULL);
		count++;
	}
	return (buf);
}

static void	move_offset(int count, int fd)
{
	char	chr;
	ssize_t	read_cnt;

	read_cnt = 1;
	chr = '\0';
	while (count < SSIZE_MAX && read_cnt > 0)
	{
		read_cnt = read(fd, &chr, 1);
		if (chr == '\n')
			return ;
		count++;
	}
}

char	*get_next_line(int fd)
{
	char	*lnstr;
	int		count;
	char	*retstr;

	if (BUFFER_SIZE > SSIZE_MAX)
		return(NULL);
	if (!fd)
		return (NULL);
	lnstr = get_line(fd);
	if (!lnstr)
		return (NULL);
	count = (int)ft_strlen(lnstr);
	retstr = ft_calloc(sizeof(char), sizeof(char) * count + 1);
	if (!retstr)
		return (NULL);
	if (lnstr[count - 1] != '\n')
		move_offset(count, fd);
	ft_strlcpy(retstr, lnstr, count);
	free(lnstr);
	return (retstr);
}
