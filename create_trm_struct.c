/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trm_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:31:05 by vkurkela          #+#    #+#             */
/*   Updated: 2019/11/18 15:24:23 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	starting_point(char *block)
{
	int i;

	i = 0;
	while (block[i] != '#')
		i++;
	return (i);
}

int	struct_creator(t_trm *tetriminos, char **blocks)
{
	int count;
	int	rows;
	int	cols;
	int i;
	int x;

	i = 0;
	while (blocks[i])
	{
		rows = 0;
		cols = 0;
		count = 4;
		x = starting_point(blocks[i]) + 1;
		printf("******************\n");
		if (blocks[i][x] == '.')
			rows++;
		else
			cols++;
		while (blocks[i][x])
		{
			while (blocks[i][x] == '#')
			{
				x++;
				printf("rows: %d\n", rows);
				printf("cols: %d\n", cols);
				if (blocks[i][x] == '.')
					rows++;
				else
					cols++;
			}
			x++;
		}
		i++;
	}
	return (0);
}
