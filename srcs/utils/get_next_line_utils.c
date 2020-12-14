/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:57:13 by timlecou          #+#    #+#             */
/*   Updated: 2019/12/03 17:13:18 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getline(char *str)
{
	int		length;
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	length = i;
	if (!(line = (char*)ft_malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getrest(char *str, int *empty_rest)
{
	char *rest;

	*empty_rest = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
		{
			str++;
			if (!(rest = (char*)ft_malloc(sizeof(char) * ft_strlen(str) + 1)))
				return (NULL);
			rest = ft_strcpy(rest, str);
			return (rest);
		}
		str++;
	}
	*empty_rest = 1;
	return (NULL);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char*)s1;
	str2 = (char*)s2;
	i = -1;
	j = -1;
	if (!(dest = ft_malloc(sizeof(char*) *
	(ft_strlen(str1) + ft_strlen(str2) + 1))))
		return (NULL);
	while (str1[++i])
		dest[i] = str1[i];
	while (str2[++j])
		dest[i + j] = str2[j];
	dest[i + j] = '\0';
	ft_free(str1);
	return (dest);
}
