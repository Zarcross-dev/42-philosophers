# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 16:52:35 by beboccas          #+#    #+#              #
#    Updated: 2023/10/22 16:52:35 by beboccas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re out
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = srcs/ft_printf_utils srcs/ft_printf srcs/ft_print_char srcs/ft_print_str srcs/ft_print_int srcs/ft_put_digit srcs/ft_put_upper_digit srcs/ft_print_pointer srcs/ft_print_unsigned_int
CFILES= $(SRCS:%=%.c)
OFILES= $(CFILES:.c=.o)

LIBFT = libft.a
NAME = libftprintf.a

all: $(NAME)
	@echo "✅ - \033[0;32mft_printf compiled!\033[0m"
$(NAME): $(OFILES) $(LIBFT_OFILES)
	ar -rc $(NAME) $(LIBFT_OFILES) $(OFILES)	

clean:
	rm -f $(LIBFT_OFILES) $(OFILES)

fclean: clean
	rm -f $(NAME)
	@echo "🗑️  - \033[0;31mft_printf cleaned!\033[0m"

re: fclean all

out : 
	gcc srcs/*.c libft/*.c -Wall -Wextra -Werror -g -fsanitize=leak