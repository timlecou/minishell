/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:08:38 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/13 23:08:40 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_utils_sub_env(int *i, char *str)
{
	int j;

	j = 0;
	while (str[*i + j] != '\0' && str[*i + j] != '\'')
		j++;
	*i += j;
}

int		count_prec_bs(char *str, int i)
{
	int	count;

	count = 0;
	while (i >= 0 && str[i] == '\\')
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_sub_env(t_env *env, char *str, int i)
{
	int		j;
	char	*name;
	char	*new;

	new = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == '\'')
			ft_utils_sub_env(&i, str);
		if (str[i] == '$' && ft_is_alnum(str[i + 1]))
		{
			if ((i > 0 && count_prec_bs(str, i - 1) % 2 == 0) || i == 0)
			{
				i++;
				j = 0;
				while (ft_is_alnum(str[i + j]))
					j++;
				name = ft_substr(str, i - 1, j + 1);
				new = replace_str(str, name, get_env_value(env, &name[1]));
				i += j - 1;
			}
		}
		i++;
	}
	return ((!new ? str : new));
}

void	replace_wave(char **s, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	str = *s;
	while (str[i] != '\0')
	{
		if (str[0] == '~')
			str = ft_strjoin(get_env(data->env, "HOME"), &str[1]);
		i++;
	}
	*s = str;
}
