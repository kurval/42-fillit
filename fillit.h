/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:46:51 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/11/15 16:39:43 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./includes/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define MAX 25

typedef struct	s_trm
{
	int		rows[2];
	int		cols[2];
	char	alphabet;
}				t_trm;

int				check_block_shape(char *str);
int				check_block_chars(char *str);
int				check_file(int fd, char **blocks);
int				check_lines(char **str, char *line, int fd, int n);
int				struct_creator(char *str, int block_count);
void			struct_creator_two(char *str, int i, char kirjain);

#endif
