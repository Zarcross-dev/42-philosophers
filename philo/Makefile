# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 04:27:02 by beboccas          #+#    #+#              #
#    Updated: 2024/05/18 04:44:02 by beboccas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
HEADER	=	./inc/
CC		=	gcc
CFLAGS	=	-Werror -Wall -Wextra -g -I $(HEADER) -pthread

SRCS	=	philo.c
			
OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)
			
fclean:	clean
			rm -rf $(NAME)
			
re	:	fclean all