# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 14:12:18 by mcarazo-          #+#    #+#              #
#    Updated: 2023/08/04 14:28:40 by mcarazo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSDIR		= src
OBJSDIR		= obj
INCLUDES	= inc

NAME		= pipex
BONUS		= pipex_bonus
SRCSDIR		= srcs
OBJSDIR		= objs
INCLUDES	= inc
EXTLIB		= libft

SRCS		= pipex.c pipex_utils.c
BONUS_SRCS	= pipex_bonus.c pipex_utils_bonus.c

# Compiler options
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g3 -fsanitize=address

#--------------------------------------------------------------------------------------------------------

OBJS		= $(SRCS:%.c=$(OBJSDIR)/%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(OBJS) $(EXTLIB)/$(EXTLIB).a
	@echo "Assembling $@"
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $<
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(EXTLIB) -c $< -o $@

$(EXTLIB)/$(EXTLIB).a:
	@echo "Compiling $@"
	@$(MAKE) -s -C $(EXTLIB)

$(BONUS): $(BONUS_OBJS) $(EXTLIB)/$(EXTLIB).a
	@echo "Assembling bonus $@"
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $<
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(EXTLIB) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)
	@$(MAKE) -s -C $(EXTLIB) clean

fclean: clean
	rm -rf $(NAME) $(BONUS)
	@$(MAKE) -s -C $(EXTLIB) fclean

re: fclean all

test: all
	./$(NAME)

.PHONY: all clean fclean re test bonus
