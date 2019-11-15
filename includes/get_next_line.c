/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:26:05 by vkurkela          #+#    #+#             */
/*   Updated: 2019/11/14 13:52:18 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** This function checks if it finds linebreak and stores
** the line ending '\n' to *line variable and sets *s
** variable to right location. If there is no linebreak
** it copies the end and frees the *s variable. If it reach
** the end of a file we can free the memory of *s beacause.
*/

static int	get_line(char **s, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		temp = ft_strdup(&((*s)[len + 1]));
		ft_strdel(s);
		*s = temp;
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
		return (0);
	}
	return (1);
}

/*
** Returns a value 1 if line has been read,
** 0 when the reading has been completed or
** -1 if an error has happened respectively.
*/

static int	ret_value(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (get_line(&s[fd], line));
}

/*
** Gnl checks if static variable is empty and then allocates
** memory for it using buff and see if it contains line break
** character. Next iterations will store the data from fd and
** stores it after the previous data. Then it  must free
** the memory and copy temp andress so it won't loose the data.
** If line break occurs then function breaks and calls next function.
*/

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	static char	*s[FD_MAX];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (ret_value(s, line, ret, fd));
}
