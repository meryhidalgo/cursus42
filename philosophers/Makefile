# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 11:37:17 by mcarazo-          #+#    #+#              #
#    Updated: 2024/03/27 13:04:36 by mcarazo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSDIR		= src
OBJSDIR		= obj
INCLUDES	= inc

NAME		= philo
SRCSDIR		= srcs
OBJSDIR		= objs
INCLUDES	= in

SRCS		= philo.c philo_utils.c routine.c check_philos.c init.c

# Compiler options
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=thread -g #-g3 -fsanitize=address 

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
