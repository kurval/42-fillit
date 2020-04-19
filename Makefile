# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 11:46:09 by vkurkela          #+#    #+#              #
#    Updated: 2020/04/19 09:33:20 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = sources/main.c sources/validation.c sources/create_arr_structs.c \
	sources/solver.c sources/helper_funtions.c

OBJ = main.o validation.o create_arr_structs.o \
	solver.o helper_funtions.o

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

HEADERS = includes/fillit.h

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

all: $(NAME)

$(NAME):
	@echo "$(WHT)Compiling libft...$(EOC)"
	@make -C libft
	@echo "$(GREEN)Libft done.$(EOC)"
	@echo "$(WHT)Compiling Fillit...$(EOC)"
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(GREEN)Fillit build completed.$(EOC)"

clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	@/bin/rm -f $(OBJ)
	@make -C libft clean
	@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	@echo "$(WHT)Removing object- and binary -files...$(EOC)"
	@/bin/rm -f $(NAME)
	@make -C libft fclean
	@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re
