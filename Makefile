# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 11:46:09 by vkurkela          #+#    #+#              #
#    Updated: 2019/11/15 16:47:08 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c validation.c create_trm_struct.c

OBJ = $(SRC:.c=.o)

HEADERS = fillit.h

LIBFT = includes/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	@${MAKE} -C includes

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)
	@${MAKE} -C includes clean

fclean: clean
	/bin/rm -f $(NAME)
	@${MAKE} -C includes fclean

re: fclean all

.PHONY: all clean fclean re
