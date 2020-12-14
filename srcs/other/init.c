/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:37:09 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 08:37:25 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_inc_shlvl(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (str)
		i = ft_atoi(str);
	tmp = ft_itoa(i + 1);
	return (tmp);
}

t_data	init_data_struct(void)
{
	t_data	data;

	data.nb_cmd = 0;
	data.cmd = NULL;
	data.env = NULL;
	data.envp = NULL;
	data.last_ret = 0;
	data.status = 0;
	return (data);
}

t_cmd	init_cmd_struct(void)
{
	t_cmd	cmd;

	cmd.name = NULL;
	cmd.av = NULL;
	cmd.ac = 0;
	cmd.red = NULL;
	cmd.red_nb = 0;
	return (cmd);
}
