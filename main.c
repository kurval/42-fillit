/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:37:58 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/11/18 11:05:37 by vkurkela         ###   ########.fr       */
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
		printf("Invalid input");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (check_file(fd, blocks) != 0)
			printf("\n\nKaikki palikat kunnossa\n\n");
		else
			printf("\n\nValidation failed !\n\n");
		while (blocks[i] != 0)
		{
			printf("%s\n", blocks[i]);
			i++;
		}
		struct_creator(arr_tetriminos, blocks);
		printf("tetriminos cols %d\n", arr_tetriminos[0].cols[1]);
		printf("tetriminos rows  %d\n", arr_tetriminos[3].rows[2]);
		printf("tetriminos rows  %c\n", arr_tetriminos[3].alphabet);
	}
	return (0);
}
