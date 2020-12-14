/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:26:39 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 09:31:43 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sort_env_tab(char **env, int i)
{
	int		j;
	char	*x;
	char	*name_1;
	char	*name_2;

	x = NULL;
	while (env[i])
	{
		j = i + 1;
		while (env[j])
		{
			name_1 = ft_get_env_name(env[i]);
			name_2 = ft_get_env_name(env[j]);
			if (ft_strcmp(name_1, name_2) > 0)
			{
				x = env[i];
				env[i] = env[j];
				env[j] = x;
			}
			ft_free(name_1);
			ft_free(name_2);
			j++;
		}
		i++;
	}
}

char	*ft_get_env(t_data *data, char *str, int i)
{
	t_env	*tmp;

	tmp = data->env;
	i++;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(&str[i], tmp->name, ft_strlen(tmp->name)) == 0)
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return ("");
}

char	*ft_get_env_value(char *str)
{
	int		i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[i - 1] == '=' && i - 1 >= 0
		&& (str[i] == '\'' || str[i] == '"'))
		{
			i++;
			return (ft_substr(str, i + 2, ft_strlen(&str[i]) - 1));
		}
		if (str[i] == '=')
			return (ft_substr(str, i + 1, ft_strlen(&str[i])));
		i++;
	}
	return (NULL);
}

char	*ft_get_env_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (ft_substr(str, 0, i));
		i++;
	}
	return (NULL);
}

t_env	*ft_fill_env_list(char **envp)
{
	t_env	*env;
	int		i;
	char	*name;
	char	*value;

	i = 0;
	env = NULL;
	while (envp[i] != NULL)
	{
		name = ft_get_env_name(envp[i]);
		value = ft_get_env_value(envp[i]);
		ft_lstadd_back(&env, ft_lstnew(name, value));
		ft_free(name);
		ft_free(value);
		name = NULL;
		value = NULL;
		i++;
	}
	ft_lstadd_back(&env, ft_lstnew("?", "0"));
	return (env);
}
