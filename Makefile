# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 11:46:09 by vkurkela          #+#    #+#              #
#    Updated: 2019/11/22 15:46:25 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = sources/main.c sources/validation.c sources/create_arr_structs.c \
	sources/solver.c sources/helper_funtions.c

OBJ = main.o validation.o create_arr_structs.o \
	solver.o helper_funtions.o

HEADERS = sources/fillit.h

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

all: $(NAME)

$(NAME): 
	@${MAKE} -C libft
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)
	@${MAKE} -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@${MAKE} -C libft fclean

re: fclean all

.PHONY: all clean fclean re
