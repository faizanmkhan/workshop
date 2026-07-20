# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/29 20:25:33 by faikhan           #+#    #+#              #
#    Updated: 2026/06/29 23:30:47 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= infotype
SRCS	= main.cpp Base.cpp
OBJS	= $(SRCS:.cpp=.o)
CC		= c++
CFLAGS	= -g3 -Wall -Werror -Wextra -std=c++98 -fsanitize=address
RM		= rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re