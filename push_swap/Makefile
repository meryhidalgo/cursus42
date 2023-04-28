# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 15:18:06 by mcarazo-          #+#    #+#              #
#    Updated: 2023/04/28 19:36:54 by mcarazo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= push_swap.c push_swap.h operations.c min_max.c sorted.c help_libft.c manage_numbers.c

OBJS	= ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

TARGET	= push_swap
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs

${TARGET}:	${OBJS}
			${CC} ${CFLAGS} ${SRCS} -o ${TARGET}

all:		${TARGET}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${TARGET}

re:			fclean all

.PHONY:		all clean fclean re
