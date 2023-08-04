# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 15:18:06 by mcarazo-          #+#    #+#              #
#    Updated: 2023/08/02 15:54:26 by mcarazo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSDIR		= src
OBJSDIR		= obj
INCLUDES	= inc

SRCS	= ft_atoi.c ft_lst.c ft_split.c mng_numbers.c min_max.c \
			operations.c search_nb.c sorted.c mng_errors.c push_swap.c

OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

NAME	= push_swap
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Assembling $@"
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $<
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJSDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
