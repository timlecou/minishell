/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:59:08 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 10:00:18 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lstadd_back_arg(t_arg **lst, t_arg *new)
{
	t_arg	*begin;

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

t_arg	*ft_lstnew_arg(char *str)
{
	t_arg	*a;

	if (!(a = ft_malloc(sizeof(t_arg))))
		return (NULL);
	a->str = ft_strdup(str);
	a->next = NULL;
	return (a);
}

void	print_list(t_arg *arg)
{
	t_arg	*a;

	a = arg;
	while (a)
	{
		a = a->next;
	}
}

char	*list_to_pchar(t_arg *arg)
{
	int		size;
	char	*new;
	t_arg	*a;
	int		i;
	int		j;

	i = -1;
	a = arg;
	size = 0;
	while (a)
	{
		size += ft_strlen(a->str);
		a = a->next;
	}
	new = ft_malloc(sizeof(char) * (size + 1));
	a = arg;
	while (a)
	{
		j = -1;
		while (a->str[++j])
			new[++i] = a->str[j];
		a = a->next;
	}
	new[++i] = '\0';
	return (new);
}

void	clear_list(t_arg **arg)
{
	t_arg	*tmp;
	void	*t;

	tmp = *arg;
	while (tmp)
	{
		ft_free(tmp->str);
		t = tmp->next;
		ft_free(tmp);
		tmp = t;
	}
	ft_free(tmp);
	*arg = NULL;
}
