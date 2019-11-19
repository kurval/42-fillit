/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:37:58 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/11/19 14:01:54 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	t_trm	arr_tetriminos[MAX];
	int		fd;
	char	*blocks[27];
	int i;

	i = 0;
	if (argc != 2)
		ft_putstr("Invalid input\n");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(check_file(fd, blocks)))
		{
			ft_putstr("ERROR\n");
			return (0);
		}
		struct_creator(arr_tetriminos, blocks);
		solver(arr_tetriminos);
	}
	return (0);
}
