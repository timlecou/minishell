/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:21:16 by timlecou          #+#    #+#             */
/*   Updated: 2020/04/15 16:47:40 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(t_data *data, int index)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->name, "PWD", 3) == 0)
		{
			ft_putstr(tmp->value);
			data->tab[index].ret = 0;
			write(1, "\n", 1);
			return ;
		}
		tmp = tmp->next;
	}
	data->tab[index].ret = 0;
	ft_quit(0);
}
