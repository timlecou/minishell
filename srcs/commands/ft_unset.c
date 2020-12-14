/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:21:16 by timlecou          #+#    #+#             */
/*   Updated: 2020/04/15 16:47:40 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_unset(t_data *data, int index)
{
	t_cmd	cmd;
	int		i;

	i = 1;
	cmd = data->tab[index];
	while (i < cmd.ac)
	{
		ft_remove_elem_from_list(&data->env, cmd.av[i]);
		i++;
	}
	data->tab[index].ret = 0;
}
