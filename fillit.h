/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:45:01 by vkurkela          #+#    #+#             */
/*   Updated: 2019/11/25 14:45:05 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./includes/libft.h"
# include <fcntl.h>

# define MAX 27

typedef struct	s_trm
{
	int		rows[3];
	int		cols[3];
	char	alphabet;
}				t_trm;

int				validate_file(int fd, char **blocks);
char			**make_bigger_map(int mapsize, char **map);
int				struct_creator(t_trm *tetriminos, char **blocks);
char			**solver(t_trm *arr_tetriminos);
void			print_map(char **map);

#endif
