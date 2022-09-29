# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:40:16 by mcarazo-          #+#    #+#              #
#    Updated: 2022/09/29 20:47:41 by mcarazo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_isdigit.c  ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c \
		ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

OBJS	= ${SRCS:.c=.o}

BONUS_SRCS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstclear_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS	= ${BONUS_SRCS:.c=.o}
NAME	= libft.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs
BONUS = .

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

${BONUS}:	${OBJS} ${BONUS_OBJS}
			${AR} ${NAME} ${OBJS} ${BONUS_OBJS}

bonus:		${BONUS}

.PHONY:		all clean fclean re bonus
