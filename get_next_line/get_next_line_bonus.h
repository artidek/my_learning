/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:55:49 by aobshatk          #+#    #+#             */
/*   Updated: 2025/01/22 16:47:52 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;
typedef struct s_files
{
	int				fd;
	t_list			*t_list;
	struct s_files	*next;
}					t_files;

char				*get_next_line(int fd);
void				clear_list(t_list **next_line);
void				extract_str(t_list *temp, char **curline);
void				get_line(int fd, t_list **next_line);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
t_list				*init_list(int fd);
t_list				*ft_lstnew(char *cont);
t_list				*check_nl(t_list *next_line);
int					lststrlen(t_list *next_line);
#endif
