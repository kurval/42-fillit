/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funtions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:12:50 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/19 09:56:40 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	print_colors(char plc)
{
	int place;

	place = (int)plc % 5;
	if (plc == '.')
	{
		printf(WHT "." EOC);
		return ;
	}
	place == 0 ? printf(RED "%c" EOC, plc) : 0;
	place == 1 ? printf(GRE "%c" EOC, plc) : 0;
	place == 2 ? printf(YEL "%c" EOC, plc) : 0;
	place == 3 ? printf(MAG "%c" EOC, plc) : 0;
	place == 4 ? printf(CYA "%c" EOC, plc) : 0;
	place == 5 ? printf(BLU "%c" EOC, plc) : 0;
}

void	print_status(char **map)
{
	int i;
	int j;

	i = 0;
	system("clear");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			print_colors(map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	usleep(17000);
}

char	**make_bigger_map(int mapsize, char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(map = (char**)malloc(sizeof(char*) * mapsize + 1)))
		return (NULL);
	while (x < mapsize)
	{
		if (!(map[x] = (char*)malloc(sizeof(char) * mapsize + 1)))
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

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
