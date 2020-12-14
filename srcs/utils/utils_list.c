/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:53:48 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 09:57:27 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_listsize(t_env *env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**ft_list_to_char(t_env *env)
{
	t_env	*tmp;
	char	**ret;
	int		i;
	char	*tmp2;

	i = 0;
	tmp = env;
	tmp2 = NULL;
	if (!(ret = (char**)ft_malloc(sizeof(char*) * (ft_listsize(env) + 1))))
		return (NULL);
	while (tmp)
	{
		ret[i] = ft_strjoin(tmp->name, "=");
		tmp2 = ret[i];
		ret[i] = ft_strjoin(ret[i], tmp->value);
		ft_free(tmp2);
		tmp2 = NULL;
		i++;
		tmp = tmp->next;
	}
	ret[i] = 0;
	return (ret);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*begin;

	begin = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst && *lst && new)
	{
		begin = *lst;
		while (begin->next)
			begin = begin->next;
		begin->next = new;
	}
}

void	ft_utils_list_rmv(t_env *list, char *name, t_env *ex)
{
	while (list)
	{
		if (ft_strcmp(list->name, name) == 0)
		{
			if (list->next == NULL)
				ex->next = NULL;
			else
				ex->next = list->next;
			ft_del_elem(list);
			return ;
		}
		ex = list;
		list = list->next;
	}
}

void	ft_remove_elem_from_list(t_env **env, char *name)
{
	t_env	*list;
	t_env	*ex;

	if (!env || !*env)
		return ;
	ex = NULL;
	list = *env;
	if (ft_strcmp(list->name, name) == 0)
	{
		if (list->next == NULL)
		{
			ft_del_elem(list);
			*env = NULL;
			return ;
		}
		*env = list->next;
		ft_del_elem(list);
		return ;
	}
	ft_utils_list_rmv(list, name, ex);
}
