/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:38:19 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 09:39:15 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_count_commands(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < (int)ft_strlen(str))
	{
		if ((str[i] != c && i == 0) || (str[i] != c && str[i - 1] == c))
			count++;
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\0')
				i++;
		}
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i] != '\0')
				i++;
		}
		i++;
	}
	return (count);
}

int		ft_utils_split(const char *s, int i, int j, char c)
{
	j = 0;
	while (s[i + j] != c && i + j < (int)ft_strlen(s))
	{
		if (s[i + j] == '\'')
		{
			j++;
			while (s[i + j] != '\'' && s[i + j] != '\0')
				j++;
		}
		if (s[i + j] == '\"')
		{
			j++;
			while (s[i + j] != '\"' && s[i + j] != '\0')
				j++;
		}
		j++;
	}
	return (j);
}

char	**ft_split_args(const char *s, char c)
{
	char	**res;
	int		index;
	int		i;
	int		j;

	index = 0;
	i = 0;
	if (!s || !(res = (char**)ft_malloc(sizeof(char*)
		* (ft_count_commands(s, c) + 1))))
		return (NULL);
	while (i < (int)ft_strlen(s))
	{
		j = ft_utils_split(s, i, j, c);
		if (j > 0)
		{
			res[index] = ft_substr(s, i, j);
			index++;
			i += j - 1;
		}
		i++;
	}
	res[index] = 0;
	return (res);
}

int		count_double_array(void **p)
{
	int	i;

	i = 0;
	while (p)
		i++;
	return (i);
}
