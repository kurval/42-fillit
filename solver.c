/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:07:35 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/11/19 18:17:34 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

/* 
** Makes bigger map after every possible moves.
*/

static char	**make_bigger_map(int mapsize, char **map)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	if(!(map = (char**)malloc(sizeof(char*) * mapsize + 1)))
		return (NULL);
	while (x < mapsize)
	{
		if(!(map[x] = (char*)malloc(sizeof(char) * mapsize + 1)))
			return (NULL);
		while (y < mapsize)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y] = '\0';
		y = 0;
		x++;
	}
	map[x] = 0;
	return (map);
}

static int	check_placement(char **map, int x, int y, t_trm tetrimino)
{
	int mapsize;
	int i;

	i = 0;
	mapsize = 0;
	while (map[i][mapsize])
		mapsize++;
	while (i < 3)
	{	
		if (x + tetrimino.rows[i] < 0 || y + tetrimino.cols[i] < 0)
			return (0);
		if (x + tetrimino.rows[i] > mapsize || y + tetrimino.cols[i] > mapsize)
			return (0);
		if (map[x + tetrimino.rows[i]][y + tetrimino.cols[i]] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void    place_tetrimino(char **map,int x, int y, t_trm tetrimino)
{
	int i;

	i = 0;
	map[x][y] = tetrimino.alphabet;
	while (i < 3)
	{
		map[x + tetrimino.rows[i]][y + tetrimino.cols[i]] = tetrimino.alphabet;
		i++;
	}
}

static int	solver_two(t_trm *arr_tetriminos, int row, int col, char **map, int mapsize)
{
	int n;
	int mapi;

	mapi = 0;
	n = 0;
	while (arr_tetriminos[n].alphabet)
	{
		if ((col == mapsize - 1) && (row == mapsize - 1))
			return (0);
		if (col == mapsize - 1)
		{
			col = 0;
			row = row + 1;
		}
		if (map[row][col] != '.')
		{
			solver_two(arr_tetriminos, row, col + 1, map, mapsize);
			return (0);
		}
		else
		{
			if (check_placement(map, row, col, arr_tetriminos[n]) == 1)
			{
				place_tetrimino(map, row, col, arr_tetriminos[n]);
				while (map[mapi])
				{
					printf("%s\n", map[mapi]);
					mapi++;
				}
				printf("\n");
				solver_two(arr_tetriminos + 1, row, col + 1, map, mapsize);
				return (0);
			}
			else
			{
				solver_two(arr_tetriminos, row, col + 1, map, mapsize);
				return (0);
			}
		}
		n++;
	}
	return (0);
}

int 		solver(t_trm *arr_tetriminos)
{
	int solver_result;
	int mapsize;
	char **map;
	int count;

	count = 0;
	mapsize = 5;
	solver_result = 1;
	map = make_bigger_map(mapsize, map);
	while (solver_result == 1)
	{
		solver_result = solver_two(arr_tetriminos, 0, 0, map, mapsize);
		if (solver_result == 1)
		{
			mapsize++;
			ft_strdel(map);
			map = make_bigger_map(mapsize, map);
		}
	}
	return (0);
}
