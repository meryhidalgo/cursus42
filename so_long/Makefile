# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 13:26:15 by mcarazo-          #+#    #+#              #
#    Updated: 2023/10/11 09:45:47 by mcarazo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSDIR		= src
OBJSDIR		= obj
INCLUDES	= inc

NAME		= so_long
SRCSDIR		= srcs
OBJSDIR		= objs
INCLUDES	= inc

MLX			= mlx
GNL			= get_next_line

SRCS		= parse_map.c path.c create_map.c movement.c

# Compiler options
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g3 -fsanitize=address

#--------------------------------------------------------------------------------------------------------

OBJS		= $(SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(GNL)/$(GNL).a
	@echo "Assembling $@"
	$(CC) $(CFLAGS) -o $@ $^ -L$(MLX) -l$(MLX) -framework OpenGL -framework AppKit -o $(NAME)
# $(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $<
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(GNL) -I$(MLX) -c $< -o $@
# $(CC) $(CFLAGS) -I$(INCLUDES) -I$(MLX) -c $< -o $@

$(MLX)/$(MLX).a:
	@echo "Compiling $@"
	@$(MAKE) -s -C $(MLX)

$(GNL)/$(GNL).a:
	@echo "Compiling $@"
	@$(MAKE) -s -C $(GNL)

clean:
	rm -rf $(OBJSDIR)
	@$(MAKE) -s -C $(MLX) clean
	@$(MAKE) -s -C $(GNL) clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -s -C $(GNL) fclean

re: fclean all

test: all
	./$(NAME)

.PHONY: all clean fclean re test bonus
