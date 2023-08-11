# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 14:12:18 by mcarazo-          #+#    #+#              #
#    Updated: 2023/08/11 11:55:32 by mcarazo-         ###   ########.fr        #
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

LIBFT		= libft
GNL			= get_next_line

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

$(NAME): $(OBJS) $(GNL)/$(GNL).a $(LIBFT)/$(LIBFT).a
	@echo "Assembling $@"
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $<
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(GNL) -I$(LIBFT) -c $< -o $@

$(LIBFT)/$(LIBFT).a:
	@echo "Compiling $@"
	@$(MAKE) -s -C $(LIBFT)

$(GNL)/$(GNL).a:
	@echo "Compiling $@"
	@$(MAKE) -s -C $(GNL)

$(BONUS): $(BONUS_OBJS) $(GNL)/$(GNL).a $(LIBFT)/$(LIBFT).a
	@echo "Assembling bonus $@"
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $<
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(GNL) -I$(LIBFT) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)
	@$(MAKE) -s -C $(LIBFT) clean
	@$(MAKE) -s -C $(GNL) clean

fclean: clean
	rm -rf $(NAME) $(BONUS)
	@$(MAKE) -s -C $(LIBFT) fclean
	@$(MAKE) -s -C $(GNL) fclean

re: fclean all

test: all
	./$(NAME)

.PHONY: all clean fclean re test bonus
