# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 14:02:33 by aobshatk          #+#    #+#              #
#    Updated: 2025/01/28 19:53:42 by aobshatk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 			= get_next_line_utils.c get_next_line_utils_bonus.c get_next_line_bonus.c get_next_line.c
OBJS 			= $(SRCS:.c=.o)
NAME 			= get_next_line.a

CC 	  			= cc
FLAGS 			= -Wall -Wextra -Werror
RM				= rm -f
BUFFER_SIZE		?= 4096

%.o: %.c 
	$(CC) $(FLAGS) -DBUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS) $(BOBJS)


all:		$(NAME)

bonus:		$(NAME)

clean:		
	 $(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(RM) $(NAME) 
				
re:			fclean $(NAME) 

.PHONY:		 all clean fclean re
