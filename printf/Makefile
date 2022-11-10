SRCS	= ft_printf.c printf_functions.c
OBJS	= ${SRCS:.c=.o}

LIBFT_SRCS	= libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_strlen.c
LIBFT_OBJS 	= ${LIBFT_SRCS:.c=.o}

NAME	= libftprintf.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs

all:		${NAME}

${NAME}:	${OBJS} ${LIBFT_OBJS}
			${AR} ${NAME} ${OBJS} ${LIBFT_OBJS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS} ${LIBFT_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
