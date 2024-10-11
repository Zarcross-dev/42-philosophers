# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 04:27:02 by beboccas          #+#    #+#              #
#    Updated: 2024/10/11 16:19:50 by beboccas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	gcc
CFLAGS	=	-Werror -Wall -Wextra -g -I $(HEADER) -pthread

SRCS	=	srcs/philo.c \
			srcs/utils.c \
			srcs/init.c \
			srcs/exit_handler.c \
			srcs/philo_utils.c \
			srcs/philo_actions.c \
			srcs/philo_summon.c \
			
OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME):	$(OBJS) 
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
			@echo "✅ - \033[0;32mPhilosophers compiled!\033[0m"

%.o:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "🔄 - Compiling $@ \033[0;32mOK\033[0m"

clean:
			@rm -rf $(OBJS)
			@echo "🗑️  - \033[0;31mPhilosophers cleaned!\033[0m"
			
fclean:	clean
			@rm -rf $(NAME)	
			
re	:	fclean all