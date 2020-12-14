/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:09:07 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/15 18:32:29 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_has_bs(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_bs(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == '\\')
		i++;
	return (i / 2);
}

char	*test(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '\\')
		{
			i += ft_count_bs(&str[i]);
			j = i;
			while (str[i] == '\\' && str[i] != '\0')
				i++;
			tmp = ft_strdup(str);
			str = ft_strjoin(ft_substr(tmp, 0, j),
			ft_substr(tmp, i, ft_strlen(str) - i));
		}
		i++;
	}
	return (str);
}

char	**add_scd(char **arr, char *str, int size)
{
	int		i;
	char	**new;

	i = 2;
	new = malloc(sizeof(char*) * (size + 1));
	new[0] = arr[0];
	new[1] = str;
	while (i < size)
	{
		new[i + 1] = arr[i];
		i++;
	}
	return (new);
}
