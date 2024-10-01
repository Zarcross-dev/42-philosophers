.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC		= ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
				ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ		= ${SRC:.c=.o}

SRCB	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c
OBJB	= ${SRCB:.c=.o}

CFLAGS	= -Wall -Werror -Wextra
HEAD	= libft.h
CC		= gcc
AR		= ar rcs
RM		= rm -f
NAME	= libft.a
# ---------------------------------------------------------------------------- #
# 									Regles								       #
# ---------------------------------------------------------------------------- #
all:		${NAME}

${NAME}:	${OBJ}
	@${AR} ${NAME} ${OBJ}
	@echo "✅ - \033[0;32mLibft compiled!\033[0m"

%.o:		%.c ${HEAD}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJ} ${OBJB}

fclean:		clean
	@${RM} ${NAME}
	@echo "🗑️  - \033[0;31mLibft cleaned!\033[0m"

re:			fclean all

bonus:		${OBJB}
	@${AR} ${NAME} ${OBJB}
