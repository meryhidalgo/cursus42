<<<<<<< HEAD
SRCS	= ft_printf.c printf_functions.c
OBJS	= ${SRCS:.c=.o}

LIBFT_SRCS	= libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_strlen.c
LIBFT_OBJS 	= ${LIBFT_SRCS:.c=.o}
=======
SRCS	= 

OBJS	= ${SRCS:.c=.o}
>>>>>>> b49b65836c99b69541a2a15577022f95d7eb527a

NAME	= libftprintf.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs
<<<<<<< HEAD

all:		${NAME}

${NAME}:	${OBJS} ${LIBFT_OBJS}
			${AR} ${NAME} ${OBJS} ${LIBFT_OBJS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS} ${LIBFT_OBJS}
=======
MAKE	= make -C
LIBFT	= libft

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}
>>>>>>> b49b65836c99b69541a2a15577022f95d7eb527a

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
