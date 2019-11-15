/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:37:58 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/11/15 09:54:04 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	t_trm	arr_tetriminos[MAX];
	int		fd;

	if (argc != 2)
		printf("Invalid input");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (check_file(fd) == 1)
			printf("\n\nKaikki palikat kunnossa\n\n");
		else
			printf("\n\nValidation failed !\n\n");
	}
	return (0);
}
