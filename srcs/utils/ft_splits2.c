/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:39:44 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 09:40:25 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && i == 0) || (str[i] != c && str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		index;
	int		i;
	int		j;

	index = 0;
	i = 0;
	if (!s || !(res = (char**)ft_malloc(sizeof(char*)
		* (count_words(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
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
