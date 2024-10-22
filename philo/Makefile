# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 04:27:02 by beboccas          #+#    #+#              #
#    Updated: 2024/10/22 02:16:59 by beboccas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	gcc
CFLAGS	=	-Werror -Wall -Wextra -g -I $(HEADER) -pthread

SRCS	=	srcs/philo.c \
			srcs/init.c \
			srcs/exit_handler.c \
			srcs/dinner.c \
			srcs/utils/libft_utils.c \
			srcs/utils/safe_utils.c \
			srcs/utils/dinner_utils.c \
			srcs/utils/time_utils.c 
			
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