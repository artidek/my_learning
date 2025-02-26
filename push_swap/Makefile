SRCS		= ./sources/final_merge.c ./sources/final_sort.c ./sources/ft_atoil.c ./sources/init_stack.c  ./sources/initial_merge_sort.c \
			  ./utils/list_utils.c ./utils/optimization_utils.c ./utils/pswp_utils.c ./utils/sort_utils.c ./utils/helpers.c ./utils/find_duplicates.c\
			  
OBJS		= $(SRCS:.c=.o)

FTPRINTFPATH	= ./ft_printf
FTPRINTF		= $(FTPRINTFPATH)/libftprintf.a

CFLAGS		= -Wall -Wextra -Werror -g
CC			= cc

LIBR		= push_swap.a
NAME		= push_swap

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBR)
	$(CC) $(CFLAGS) main.c -g -o push_swap $(LIBR)

all: $(NAME)

$(FTPRINTF): 
		make -C $(FTPRINTFPATH) all

$(LIBR): $(FTPRINTF) $(OBJS)
		cp $(FTPRINTF) $(LIBR)
		ar rcs $(LIBR) $(OBJS)

fclean: 
			make -C $(FTPRINTFPATH) fclean
			$(RM) $(OBJS)
			$(RM) $(LIBR)
			$(RM) push_swap
			
PHONY: fclean all
