# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 22:53:55 by nileempo          #+#    #+#              #
#    Updated: 2024/02/04 22:08:10 by nileempo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	init_free.c \
	checkers/input_error.c \
	checkers/cmd_error.c \
	process/process.c \

INC_PATH = ./includes

RESET = \033[0m
GREEN = \033[32m
RED = \033[31m
BLUE = \033[34m
YELLOW = \033[33m

NAME = pipex

HEADER = pipex.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

RM = rm -f

OBJS = $(SRCS:.c=.o)

.c.o: $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)
	@echo "$(GREEN)--- Making objets pipexs : $(YELLOW)$@$(RESET)"

$(NAME): $(OBJS)
	make -C ./LIBFT
	@echo "$(GREEN)--- Making the executable : $(YELLOW)$(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) LIBFT/libft.a

all: $(NAME)

clean:
	make clean -C ./LIBFT
	$(RM) $(OBJS) $(LIBFT)
	@echo "$(RED)--- Objects pipexs $(YELLOW)$(OBJS) $(RED)have been deleted.$(RESET)"

fclean: clean
	make fclean -C ./LIBFT
	$(RM) $(NAME)
	@echo "$(RED)--- The executable $(YELLOW)$(NAME) $(RED)have been deleted.$(RESET)"

re: fclean all
	@echo "$(GREEN)--- Rebuilding everything.$(RESET)"

.PHONY: all clean fclean re
