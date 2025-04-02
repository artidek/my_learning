SRCS		= init_stack.c push_swap.c ft_atoil.c swap.c \
			  push.c rotate.c reverse_rotate.c split_stack.c \
			  sort_utils.c optimization_utils.c list_utils.c \
			  merge_after_sort.c final_sort.c

OBJS		= $(SRCS:.c=.o)

LIBFTPATH	= ./libft
LIBFT		= $(LIBFTPATH)/libft.a

CFLAGS		= -Wall -Wextra -Werror -g
CC			= cc

LIBR		= push_swap.a
NAME		= push_swap

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBR)
	$(CC) $(CFLAGS) -g -o push_swap $(LIBR)

all: $(NAME)

$(LIBFT): 
		make -C $(LIBFTPATH) bonus

$(LIBR): $(LIBFT) $(OBJS)
		cp $(LIBFT) $(LIBR)
		ar rcs $(LIBR) $(OBJS)

fclean: 
			make -C $(LIBFTPATH) fclean
			$(RM) $(OBJS)
			$(RM) $(LIBR)
			$(RM) push_swap
			
PHONY: fclean all
