/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:08:13 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/17 17:58:34 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		*get_env(t_env *env, char *var)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->name, var, ft_strlen(var)) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int			ft_utils_count_args(char *str, int index)
{
	if (str[index] == '\'')
	{
		index++;
		while (str[index] != '\0' && !(str[index] == '\''
				&& count_prec_bs(str, index - 1) % 2 == 0))
			index++;
	}
	if (str[index] == '"')
	{
		index++;
		while (str[index] != '\0' && !(str[index] == '"'
				&& count_prec_bs(str, index - 1) % 2 == 0))
			index++;
	}
	if (str[index] != '\0')
		index++;
	return (index);
}

int			ft_count_args(char *str, int index)
{
	int	count;

	count = 0;
	while (index < (int)ft_strlen(str))
	{
		if (str[index] != ' ' && str[index] != '\t')
		{
			count++;
			while ((str[index] != ' ' && str[index] != '\t')
			&& index < (int)ft_strlen(str))
				index = ft_utils_count_args(str, index);
			index--;
		}
		index++;
	}
	return (count);
}

void		ft_utils_args2(char *str, int *d, int *k, int index)
{
	*d = *d + 1;
	*k = index + *d;
	while (str[index + *d] != '\0')
	{
		if (str[index + *d] == '\''
			&& count_prec_bs(str, index + *d - 1) % 2 == 0)
			return ;
		*d = *d + 1;
	}
}

void		ft_utils_args3(char *str, int *d, int *k, int index)
{
	*d = *d + 1;
	*k = index + *d;
	while (str[index + *d] != '\0')
	{
		if (str[index + *d] == '"'
			&& count_prec_bs(str, index + *d - 1) % 2 == 0)
			return ;
		*d = *d + 1;
	}
}
