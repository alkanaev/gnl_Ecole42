/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:33:04 by alkanaev          #+#    #+#             */
/*   Updated: 2020/01/14 20:11:45 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(char *dest, char *src, size_t len)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		src = src + (len - 1);
		dest = dest + (len - 1);
		while (len > 0)
		{
			*dest-- = *src--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*dest++ = *src++;
			len--;
		}
	}
	return (dest);
}

void	freeing_for_str(const char *s1)
{
	if (s1)
		free((char *)s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*res;

	if (s2 == NULL)
		return (NULL);
	len1 = (s1 == NULL) ? 0 : ft_strlen((char*)s1);
	len2 = ft_strlen((char*)s2);
	if (!(res = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[i - len1] && s2[i - len1] != '\n')
	{
		res[i] = s2[i - len1];
		i++;
	}
	res[i] = '\0';
	freeing_for_str(s1);
	return (res);
}

int		ft_lennchr(const char *s, int sym)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == sym)
			return (i);
		i++;
	}
	if (s[i] == sym)
		return (i);
	return (-1);
}
