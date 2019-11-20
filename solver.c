/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:07:35 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/11/20 18:15:06 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"
#include <unistd.h>

/* 
** Makes bigger map after every possible moves.
*/
static char **make_bigger_map(int mapsize, char **map)
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
static int  check_placement(char **map, int x, int y, t_trm tetrimino)
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
        if (x + tetrimino.rows[i] > mapsize - 1 || y + tetrimino.cols[i] > mapsize - 1)
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
static int  solver_two(t_trm *arr_tetriminos, char **map, int mapsize)
{
    int x;
	int y;

	x = 0;
	y = 0;
	if (!(arr_tetriminos->alphabet))
		return (1);
	while (x < mapsize)
	{
		while (y < mapsize)
		{
			if (map[x][y] == '.')
			{
				if (check_placement(map, x, y, *arr_tetriminos) == 1)
				{
					place_tetrimino(map, x, y, *arr_tetriminos);
					if (solver_two(arr_tetriminos + 1, map, mapsize))
						return (1);
				}
			}
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}


int         solver(t_trm *arr_tetriminos)
{
	int solver_result;
	int mapsize;
	char **map;
	int count;
	int i;

	i = 0;
	count = 0;
	mapsize = 2;
	solver_result = 0;
	map = make_bigger_map(mapsize, map);
	while (solver_result == 0)
	{
		solver_result = solver_two(arr_tetriminos, map, mapsize);
		if (solver_result == 0)
		{
			mapsize++;
			ft_strdel(map);
			map = make_bigger_map(mapsize, map);
		}
	}
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (1);
}
