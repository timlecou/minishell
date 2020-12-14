/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:00:31 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 10:01:03 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_lstnew(char *name, char *value)
{
	t_env	*elem;

	if (!(elem = ft_malloc(sizeof(t_env))))
		return ((t_env*)NULL);
	elem->name = ft_strdup(name);
	if (ft_strncmp(name, "SHLVL", 5) == 0)
		elem->value = ft_inc_shlvl(value);
	else
		elem->value = ft_strdup(value);
	elem->next = NULL;
	return (elem);
}
