# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 11:25:21 by nileempo          #+#    #+#              #
#    Updated: 2023/07/27 11:25:03 by nileempo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	checkers/input_error.c \

RESET = \033[0m
GREEN = \033[32m
RED = \033[31m
BLUE = \033[34m
YELLOW = \033[33m

NAME = pipex

HEADER = pipex.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJS = $(SRCS:.c=.o)

.c.o: $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo "$(GREEN)--- Making objets files : $(YELLOW)$@$(RESET)"
$(NAME): $(OBJS)
	@echo "$(GREEN)--- Making the executable : $(YELLOW)$(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@echo "$(RED)--- Objects files $(YELLOW)$(OBJS) $(RED)have been deleted.$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)--- The executable $(YELLOW)$(NAME) $(RED)have been deleted.$(RESET)"

re: fclean all
	@echo "$(GREEN)--- Rebuilding everything.$(RESET)"

.PHONY: all clean fclean re
