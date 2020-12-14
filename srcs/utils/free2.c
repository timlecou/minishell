/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:35:52 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 09:37:24 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_mem	*g_mem;

void	ft_free_splitted_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
			ft_free(arr[i]);
		i++;
	}
	ft_free(arr);
}

void	*ft_malloc(int n)
{
	void	*ptr;

	ptr = malloc(n);
	ft_memadd_back(ptr);
	return (ptr);
}

void	ft_free(void *addr)
{
	t_mem	*tmp;
	t_mem	*ex;

	tmp = g_mem;
	if (addr == g_mem->addr)
	{
		g_mem = g_mem->next;
		free(tmp->addr);
		free(tmp);
		return ;
	}
	while (tmp != NULL)
	{
		if (tmp->addr == addr)
		{
			ex->next = tmp->next;
			free(tmp->addr);
			free(tmp);
			return ;
		}
		ex = tmp;
		tmp = tmp->next;
	}
}

void	free_mem(void)
{
	t_mem	*tmp;
	t_mem	*mem;
	int		i;

	i = 0;
	mem = g_mem;
	while (mem != NULL)
	{
		tmp = mem->next;
		free(mem->addr);
		free(mem);
		mem = tmp;
		i++;
	}
}
