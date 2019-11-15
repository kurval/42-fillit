/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trm_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 09:31:05 by vkurkela          #+#    #+#             */
/*   Updated: 2019/11/15 16:33:45 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* TEKEE BLOCKISTA 2D ARRAYN, jos sita johonkin tarvitaan... */
/*
char	make_block_2d(char *str)
{
	char block[4][5];
	int x;
	int y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			block[x][y] = str[count];
			count++;
			y++;
		}
		block[x][y] = '\0';
		y = 0;
		x++;
	}
	x = 0;
	return (0);
}
*/

void	struct_creator_two(char *str, int i, char kirjain)
{
	int rows[3];
	int cols[3];
	int first_hash;
	int block_count;

	block_count = 0;
	first_hash = i;

	while (++i < 16)
	{
		if (str[i] == '#')
		{
			cols[block_count] = ((i / 4) - (first_hash / 4));				// Jos tulee tilanpuute,
			printf("I ON %i  ", i);
			if		
															// niin col ja row voidaan
			else if (first_hash < 3)									// ratkaista omissa funktioissaan
				rows[block_count] = (((i + 4) % (first_hash + 4)));
			else if (first_hash % 3 == 0)
				rows[block_count] = (((i + 1) % (first_hash + 1)));
			else
			{
				printf("EKA HASH ON %i\n", first_hash);
				rows[block_count] = (((i + 4) % (first_hash + 4)));
				if (rows[block_count] > 3)
					rows[block_count] -= 4;
			}
				block_count++;
		}
	}

	printf("\nPalikka %c:n koordinaatit kiintopisteeseen nahden: - eka kivi    [%d , %d]\n", kirjain, rows[0], cols[0]);
	printf("                                                  - toka kivi   [%d , %d]\n", rows[1], cols[1]);
	printf("                                                  - toka kivi   [%d , %d]\n", rows[2], cols[2]);
	return;
}



/* ASETTAA PALIKALLE KIRJAIMEN JA ETSII ENSIMMAISEN KOHDAN MISSA LOYTYY # STR:STA */
int	struct_creator(char *str, int block_count)
{
	char	kirjain;
	int		i;

	i = 0;
	kirjain = '@' + block_count;
	while (str[i] != '#')
		i++;
	struct_creator_two(str, i, kirjain);
	printf("%s ja kirjain on: %c\n", str, kirjain);
	return (0);
}
