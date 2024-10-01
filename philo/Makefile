# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 04:27:02 by beboccas          #+#    #+#              #
#    Updated: 2024/10/01 16:53:29 by beboccas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	gcc
CFLAGS	=	-Werror -Wall -Wextra -g -I $(HEADER) -pthread

SRCS	=	srcs/philo.c \
			srcs/utils.c \
			srcs/init.c \
			srcs/exit_handler.c \
			srcs/free_structs.c \
			
OBJS	=	$(SRCS:.c=.o)

LIBFT	=	$(LIBFT_PATH)libft.a
LIBFT_PATH	=	./libft/

PRINTF	=	$(PRINTF_PATH)libftprintf.a
PRINTF_PATH	=	./ft_printf/

all	:	$(NAME)

$(NAME):	$(LIBFT) $(PRINTF) $(OBJS) 
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
			@echo "✅ - \033[0;32mPhilosophers compiled!\033[0m"

%.o:	%.c
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "🔄 - Compiling $@ \033[0;32mOK\033[0m"

$(LIBFT): 
			@$(MAKE) -C $(LIBFT_PATH) all bonus --silent

$(PRINTF):
			@$(MAKE) -C $(PRINTF_PATH) all --silent

clean:
			@rm -rf $(OBJS)
			@$(MAKE) -C $(LIBFT_PATH) clean --silent
			@$(MAKE) -C $(PRINTF_PATH) clean --silent
			@echo "🗑️  - \033[0;31mPhilosophers cleaned!\033[0m"
			
fclean:	clean
			@$(MAKE) -C $(LIBFT_PATH) fclean --silent
			@$(MAKE) -C $(PRINTF_PATH) fclean --silent
			@rm -rf $(NAME)
			
			
re	:	fclean all