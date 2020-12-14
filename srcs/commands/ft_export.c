/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:52:02 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/13 22:52:04 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_display_export_only(t_data *data, int i, int j)
{
	char	**env;
	int		start;

	env = ft_list_to_char(data->env);
	ft_sort_env_tab(env, 0);
	while (env[i])
	{
		ft_utils_export_2(&j, &start);
		while (env[i][j])
		{
			if (env[i][j] == '=' && start == 0
				&& env[i][ft_strlen(env[i]) - 1] == '=' && write(1, "=\"", 2))
			{
				start = 1;
				break ;
			}
			if (j - 1 > 0 && env[i][j - 1] == '=' && start == 0)
				ft_utils_export(&start);
			write(1, &env[i][j], 1);
			j++;
		}
		write(1, "\"\n", 2);
		i++;
	}
	env = NULL;
}

void	ft_create_var(t_data *data, char *str)
{
	char	*var;
	char	*value;

	var = ft_get_env_name(str);
	value = ft_get_env_value(str);
	ft_lstadd_back(&data->env, ft_lstnew(var, value));
	ft_free(var);
	ft_free(value);
	var = NULL;
	value = NULL;
}

int		ft_is_set(t_env *env, char *var)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, var) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_change_env_value(t_env *env, char *str, char *name)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		if (!ft_strcmp(name, tmp->name))
		{
			if (tmp->value)
			{
				ft_free(tmp->value);
				tmp->value = NULL;
			}
			tmp->value = ft_get_env_value(str);
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_export(t_data *data, int index)
{
	int		i;
	char	*name;

	i = 1;
	name = NULL;
	if (data->tab[index].ac < 2)
		ft_display_export_only(data, 0, 0);
	while (i < data->tab[index].ac)
	{
		name = ft_get_env_name(data->tab[index].av[i]);
		if (ft_is_valid_arg(data->tab[index].av[i]))
		{
			if (!ft_is_set(data->env, name))
				ft_create_var(data, data->tab[index].av[i]);
			else
				ft_change_env_value(data->env, data->tab[index].av[i], name);
		}
		ft_free(name);
		name = NULL;
		i++;
	}
	data->tab[index].ret = 0;
}
