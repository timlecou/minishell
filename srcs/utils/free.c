/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:32:27 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 09:34:47 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_mem	*g_mem;

void	ft_del_elem(t_env *elem)
{
	ft_free(elem->name);
	ft_free(elem->value);
	ft_free(elem);
}

void	ft_lstclear(t_env **lst, void (*del)(t_env *))
{
	t_env	*tmp;

	if (lst && *lst && del)
	{
		tmp = (*lst);
		while (tmp)
		{
			(*lst) = (*lst)->next;
			del(tmp);
			tmp = (*lst);
		}
	}
	*lst = NULL;
}

void	ft_free_data_struct(t_data *data)
{
	int i;

	i = 0;
	ft_free_splitted_array(data->cmd);
	while (i < data->nb_cmd)
	{
		ft_free_splitted_array(data->tab[i].av);
		i++;
	}
	ft_free(data->tab);
}

void	print_mem(void)
{
	t_mem	*mem;

	mem = g_mem;
	while (mem != NULL)
	{
		mem = mem->next;
	}
}

void	ft_memadd_back(void *addr)
{
	t_mem	*new;
	t_mem	*tmp;

	new = malloc(sizeof(t_mem));
	new->next = NULL;
	new->addr = addr;
	tmp = g_mem;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
