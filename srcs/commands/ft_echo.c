/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:54:20 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/16 18:02:22 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(t_data *data, int index)
{
	int i;
	int	is_op;

	i = 1;
	is_op = 0;
	if (data->tab[index].ac > 1)
	{
		if (ft_strcmp(data->tab[index].av[1], "-n") == 0)
		{
			is_op = 1;
			i++;
		}
	}
	while (i < data->tab[index].ac)
	{
		ft_putstr(data->tab[index].av[i]);
		if (i < data->tab[index].ac - 1)
			write(1, " ", 1);
		i++;
	}
	if (is_op == 0)
		write(1, "\n", 1);
	ft_quit(0);
}
