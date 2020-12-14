/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:25:51 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 09:26:14 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_value(t_env *env, char *name)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}

void	edit_env_value(t_env *env, char *name, char *new)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			tmp->value = ft_strdup(new);
		tmp = tmp->next;
	}
}

void	set_env(t_env **env, char *name, char *val)
{
	if (ft_is_set(*env, name))
		edit_env_value(*env, name, ft_strdup(val));
	else
		ft_lstadd_back(env, ft_lstnew(ft_strdup(name), ft_strdup(val)));
}
