/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:45:01 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/19 08:51:11 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define EOC	"\033[0m"
# define RED	"\033[1m\033[31m"
# define GRE	"\033[1m\033[32m"
# define YEL	"\033[1m\033[33m"
# define BLU    "\033[1m\033[34m"
# define MAG	"\033[1m\033[35m"
# define CYA	"\033[1m\033[36m"
# define WHT	"\033[1m\033[37m"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

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
void			free_map(char **map);
int				back_tracking(t_trm *arr_tetriminos, char **map, int mapsize);
void			remove_tetrimino(char **map, int x, int y, t_trm tetrimino);
void			place_tetrimino(char **map, int x, int y, t_trm tetrimino);
int				check_plc(char **map, int x, int y, t_trm tetrimino);
void			print_status(char **map);
#endif
