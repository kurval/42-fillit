/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:46:51 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/11/19 12:41:40 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./includes/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define MAX 25

typedef struct	s_trm
{
	int		rows[3];
	int		cols[3];
	char	alphabet;
}				t_trm;

int				check_file(int fd, char **blocks);
int				struct_creator(t_trm *tetriminos, char **blocks);
int             solver(t_trm *arr_tetriminos);
int             solver_two(t_trm *arr_tetriminos, int row, int col, char **map, int mapsize);
void            place_tetrimino(char **map, int x, int y, t_trm tetrimino);
int             check_placement(char **map, int x, int y, t_trm tetrimino);
char            **make_bigger_map(int mapsize);

#endif
