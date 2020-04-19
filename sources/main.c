/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:37:58 by jzaiedma          #+#    #+#             */
/*   Updated: 2020/04/19 09:00:50 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int argc, char **argv)
{
	t_trm	arr_tetriminos[MAX];
	int		fd;
	char	*blocks[MAX];

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(0);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1 || !(validate_file(fd, blocks)))
		{
			ft_putstr("error\n");
			return (0);
		}
		struct_creator(arr_tetriminos, blocks);
		free_map(solver(arr_tetriminos));
		close(fd);
	}
	return (0);
}
