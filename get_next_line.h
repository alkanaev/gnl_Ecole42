/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:17:32 by alkanaev          #+#    #+#             */
/*   Updated: 2020/01/14 19:27:53 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_data {
	char buff[BUFFER_SIZE + 1];
}				t_data;

int				get_next_line(int fd, char **line);

void			*ft_memmove(char *dest, char *src, size_t len);
void			freein_for_str(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strchr(const char *s, int sym);
int				ft_lennchr(const char *s, int sym);
#endif
