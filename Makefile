# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 13:26:12 by ilbonnev          #+#    #+#              #
#    Updated: 2025/01/16 17:07:29 by ilbonnev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 13:26:12 by ilbonnev          #+#    #+#              #
#    Updated: 2025/01/15 18:01:24 by ilbonnev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CHECKER		= checker

CC 			= cc
CFLAGS		= -Wall -Werror -Wextra

SRCS_PATH	= ./src
OBJ_PATH	= ./obj
INCLUDE_PATH	= ./includes

SRCS		= $(SRCS_PATH)/main.c $(wildcard $(SRCS_PATH)/push_swap/*.c) $(wildcard $(SRCS_PATH)/libft/*.c) $(wildcard $(SRCS_PATH)/get_next_line/*.c)
OBJS		= $(SRCS:$(SRCS_PATH)/%.c=$(OBJ_PATH)/%.o)


CHECKER_SRCS = $(SRCS_PATH)/checker.c $(wildcard $(SRCS_PATH)/push_swap/*.c) $(wildcard $(SRCS_PATH)/libft/*.c) $(wildcard $(SRCS_PATH)/get_next_line/*.c)
CHECKER_OBJS = $(CHECKER_SRCS:$(SRCS_PATH)/%.c=$(OBJ_PATH)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER)

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -c $< -o $@

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

bonus: $(CHECKER)
	

.PHONY: all clean fclean re bonus
