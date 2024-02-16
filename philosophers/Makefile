# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 11:37:17 by mcarazo-          #+#    #+#              #
#    Updated: 2024/02/16 14:45:52 by mcarazo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSDIR		= src
OBJSDIR		= obj
INCLUDES	= inc

NAME		= philo
SRCSDIR		= srcs
OBJSDIR		= objs
INCLUDES	= in

SRCS		= philo2.c philo_utils.c

# Compiler options
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g3 -fsanitize=address

#--------------------------------------------------------------------------------------------------------

OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Assembling $@"
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	./$(NAME)

.PHONY: all clean fclean re test
