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

SRC = main.c validation.c create_trm_struct.c solver.c helper_funtions.c

OBJ = $(SRC:.c=.o)

HEADERS = fillit.h

LIBFT = includes/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

all: $(NAME)

$(NAME): 
	@${MAKE} -C includes
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)
	@${MAKE} -C includes clean

fclean: clean
	/bin/rm -f $(NAME)
	@${MAKE} -C includes fclean

re: fclean all

.PHONY: all clean fclean re
