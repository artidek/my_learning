#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define SSIZE_MAX

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
int					length(char *str);
void				*ft_memmove(void *s1, const void *s2, size_t n);
int					realloc_str(char ***str, int size);
#endif
