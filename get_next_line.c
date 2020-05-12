/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:18:05 by alkanaev          #+#    #+#             */
/*   Updated: 2020/01/14 20:10:32 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			get_next_line(int fd, char **line)
{
	static t_data	data;
	int				res;

	if (read(fd, data.buff, 0) == -1 || fd < 0 || line == NULL ||
			BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (ft_lennchr(data.buff, '\0') > 0)
		*line = ft_strjoin(*line, data.buff);
	while (ft_lennchr(data.buff, '\n') == -1)
	{
		if ((res = read(fd, data.buff, BUFFER_SIZE)) >= 0)
		{
			data.buff[res] = '\0';
			*line = ft_strjoin(*line, data.buff);
			if (res == 0)
				return (0);
		}
	}
	res = ft_lennchr(data.buff + ft_lennchr(data.buff, '\n'), '\0') + 1;
	ft_memmove(data.buff, data.buff + ft_lennchr(data.buff, '\n') + 1, res);
	return (1);
}
