/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funtions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:12:50 by vkurkela          #+#    #+#             */
/*   Updated: 2019/11/22 15:36:39 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		free(map[i]);
		i++;
	}
	free(map);
}
