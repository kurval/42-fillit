/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:07:35 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/11/19 15:23:28 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

/* TEKEE UUDEN, SUUREMMAN KARTAN, KUN KAIKKI VAIHTOEHDOT ON KOKEILTU */
char	**make_bigger_map(int mapsize)
{
	int x;
	int y;
	char **map;
	
	if(!(map = (char**)malloc(sizeof(char*) * mapsize + 1)))
		return (NULL);

	x = 0;
	y = 0;
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


int	check_placement(char **map, int x, int y, t_trm tetrimino)
{
	int mapsize;

	mapsize = 0;
	while (map[0][mapsize])
	{
		mapsize++;
//		write(1, "M", 1);
	}
		// LISATTAVA EHTO, ETTA RETURNAA 0 JOS YRITTAA ASETTAA MAPIN ULKOPUOLELLE PALIKKAA
	int row0;
	int row1;
	int row2;
	int col0;
	int col1;
	int col2;

	row0 = tetrimino.rows[0];
	row1 = tetrimino.rows[1];
	row2 = tetrimino.rows[2];
	col0 = tetrimino.cols[0];
	col1 = tetrimino.cols[1];
	col2 = tetrimino.cols[2];
	if (x + col0 < 0 || y + row0 < 0 || x + col1 < 0 || y + row1 < 0 || x + col2 < 0 || y + row2 < 0)
		return (0);
	if (x + col0 > mapsize || y + row0 > mapsize || x + col1 > mapsize || y + row1 > mapsize || x + col2 > mapsize || y + row2 > mapsize)
		return (0);

		if (map[x + col0][y + row0] != '.')
		{
			return (0);
		}
		if (map[x + col1][y + row1] != '.')
		{
			return (0);
		}
		if (map[x + col2][y + row2] != '.')
		{	
			return (0);
		}

		return (1);
}

void	place_tetrimino(char **map,int x, int y, t_trm tetrimino)
{
	int row0;
	int row1;
	int row2;
	int col0;
	int col1;
	int col2;
	
	row0 = tetrimino.rows[0];
	row1 = tetrimino.rows[1];
	row2 = tetrimino.rows[2];
	col0 = tetrimino.cols[0];
	col1 = tetrimino.cols[1];
	col2 = tetrimino.cols[2];

	map[x][y] = tetrimino.alphabet;
	map[x + col0][y + row0] = tetrimino.alphabet;
	map[x + col1][y + row1] = tetrimino.alphabet;
	map[x + col2][y + row2] = tetrimino.alphabet;
	
	return;
}



int solver(t_trm *arr_tetriminos)
{
	int x;
	int y;
	int solver_result;
	int mapsize;
	char **map;
	int	count;
	int mapi;

	mapi = 0;
	count = 0;
	mapsize = 4;
	x = 0;
	y = 0;
	solver_result = 0;

	while (solver_result == 0)
	{
		map = make_bigger_map(mapsize);
//		printf("%i\n", arr_tetriminos->rows[1]);
		solver_result = solver_two(arr_tetriminos, 0, 0, map, mapsize);
	}
	while (map[mapi])
	{
		printf("%s\n", map[mapi]);
		mapi++;
	}
	return (0);
}




int	solver_two(t_trm *arr_tetriminos, int row, int col, char **map, int mapsize)
{
	int n;
	int mapi;

	mapi = 0;
	n = 0;

while (&arr_tetriminos[n] != 0)
{
//	write(1, "A", 1);
	if (col == mapsize)
	{
		col = 0;
		row++;
//		write(1, "Z", 1);
	}
	if (map[col][row] != '.')
	{
//		write(1, "D", 1);
		if (col == mapsize && row == mapsize)
			return (0);
		else
		{
//			write(1, "L", 1);
			solver_two(&arr_tetriminos[n], row, col + 1, map, mapsize);	
		}
	}
	else
	{
		if (check_placement(map, col, row, arr_tetriminos[n]) == 1)
		{
//			write(1, "B", 1);
			place_tetrimino(map, row, col, arr_tetriminos[n]);

				while (map[mapi])
				{
					printf("%s\n", map[mapi]);
					mapi++;
				}
				printf("\n");
			solver_two(&arr_tetriminos[n++], 0, 0, map, mapsize);
		}	
		else
		{
			write (1, "X", 1);
			solver_two(&arr_tetriminos[n], row, col++, map, mapsize);
		}
	}
	write(1, "a", 1);
	n++;
}
return (0);
}

