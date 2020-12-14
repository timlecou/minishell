/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:41:21 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 09:46:44 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_get_word_size(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_utils_replace(int i, char *str, char *rep, char *del)
{
	int				a;
	unsigned int	b;
	unsigned int	c;
	char			*new;

	if (!(new = ft_malloc(ft_strlen(str)
		- ft_strlen(del) + ft_strlen(rep) + 1)))
		return (NULL);
	a = -1;
	while (++a < i)
		new[a] = str[a];
	b = -1;
	while (++b < ft_strlen(rep))
		new[a + b] = rep[b];
	c = -1;
	while (++c < ft_strlen(str) - a - ft_strlen(del))
		new[a + b + c] = str[a + ft_strlen(del) + c];
	new[a + b + c] = '\0';
	return (new);
}

char	*replace_str(char *str, char *del, char *rep)
{
	int		i;
	int		j;

	i = 0;
	if (!str || !del || !rep)
		return (NULL);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == del[j])
			j++;
		if (del[j] == '\0')
			return (ft_utils_replace(i, str, rep, del));
		i++;
	}
	return (ft_strdup(str));
}

int		get_last_pos(char *str, char c)
{
	int	i;
	int	last;

	i = -1;
	last = -1;
	while (str[++i])
		if (str[i] == c)
			last = i;
	return (last);
}

char	*get_fd_content(int fd)
{
	char	*str;
	char	*tmp;
	char	c[2];

	str = ft_strdup("");
	while (read(fd, c, 1) > 0)
	{
		c[1] = '\0';
		tmp = str;
		str = ft_strjoin(str, c);
		ft_free(tmp);
	}
	return (str);
}
