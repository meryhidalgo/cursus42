SRCS	= 

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs
MAKE	= make -C
LIBFT	= libft

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
