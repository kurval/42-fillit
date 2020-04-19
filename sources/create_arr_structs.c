/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:31:05 by vkurkela          #+#    #+#             */
/*   Updated: 2020/04/19 08:58:48 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	starting_point(char *block)
{
	int i;

	i = 0;
	while (block[i] != '#')
		i++;
	return (i);
}

static int	check_rows(char *block, t_trm *tetriminos)
{
	int	rows;
	int	i;
	int	hash;
	int	r;

	rows = 0;
	hash = 1;
	i = starting_point(block) + 1;
	r = 0;
	while (hash++ < 4)
	{
		if (block[i] == '.')
			rows++;
		while (block[i] == '.')
			i++;
		i++;
		tetriminos->rows[r++] = rows;
	}
	return (0);
}

static int	check_cols(char *block, t_trm *tetriminos)
{
	int	i;
	int	hash;
	int	count;
	int	c;

	hash = 1;
	i = starting_point(block) + 1;
	count = 4;
	c = 0;
	while (hash++ < 4)
	{
		if (block[i] == '.')
		{
			while (block[i] == '.')
			{
				i++;
				count--;
			}
			count = 4 + count;
		}
		count--;
		i++;
		tetriminos->cols[c++] = (4 - count);
	}
	return (0);
}

int			struct_creator(t_trm *tetriminos, char **blocks)
{
	int		i;
	char	c;

	i = 0;
	c = 'A';
	while (blocks[i])
	{
		check_rows(blocks[i], &tetriminos[i]);
		check_cols(blocks[i], &tetriminos[i]);
		tetriminos[i].alphabet = c;
		c = c + 1;
		free(blocks[i]);
		i++;
	}
	return (0);
}
