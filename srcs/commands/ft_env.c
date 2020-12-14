/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:21:16 by timlecou          #+#    #+#             */
/*   Updated: 2020/04/15 16:47:40 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(t_data *data, int index)
{
	t_env	*tmp;

	index = 0;
	tmp = data->env;
	while (tmp != NULL)
	{
		ft_putstr(tmp->name);
		write(1, "=", 1);
		ft_putstr(tmp->value);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	if (index == 0)
		ft_quit(0);
}
