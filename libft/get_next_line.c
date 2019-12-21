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

static int	get_line(char **s, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		if (!(*line = ft_strsub(*s, 0, len)))
			return (-1);
		if (!(temp = ft_strdup(&((*s)[len + 1]))))
			return (-1);
		ft_strdel(s);
		*s = temp;
	}
	else
	{
		if (!(*line = ft_strdup(*s)))
			return (-1);
		ft_strdel(s);
		return (0);
	}
	return (1);
}

static int	ret_value(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (get_line(&s[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	static char	*s[FD_MAX];

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			if (!(temp = ft_strjoin(s[fd], buff)))
				return (-1);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (ret_value(s, line, ret, fd));
}
