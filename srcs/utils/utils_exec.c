/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:49:30 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 09:50:58 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_utils_exec(t_data *data, int index, int *pipe_fd)
{
	if (data->tab[index].red_nb > 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
	}
	if (ft_strcmp(data->tab[index].name, "echo") == 0)
		ft_echo(data, index);
	else if (ft_strcmp(data->tab[index].name, "pwd") == 0)
		ft_pwd(data, index);
	else if (ft_strcmp(data->tab[index].name, "env") == 0)
		ft_env(data, index);
	quit(data->tab[index].ret, "");
}

void	ft_utils_exec2(t_data *data, int index, int *pipe_fd)
{
	if (ft_strcmp(data->tab[index].name, "exit") == 0)
	{
		if (data->tab[index].ac > 1)
		{
			if (!ft_is_num(data->tab[index].av[1])
				&& ft_atoi(data->tab[index].av[1]) == 0)
				quit(2, "exit\nminishell: exit: numeric argument required !\n");
			else if (data->tab[index].ac > 2)
				quit(2, "exit\nminishell: exit: too many arguments !\n");
			quit(ft_atoi(data->tab[index].av[1]), "exit\n");
		}
		quit(0, "exit\n");
	}
	else if (ft_strcmp(data->tab[index].name, "cd") == 0)
		ft_cd(data, index);
	else if (ft_strcmp(data->tab[index].name, "unset") == 0)
		ft_unset(data, index);
	else if (ft_strcmp(data->tab[index].name, "export") == 0)
		ft_export(data, index);
	pipe(pipe_fd);
}

void	ft_utils_exec3(t_data *data, int index, int *pipe_fd)
{
	close(pipe_fd[1]);
	data->tab[index].content = get_fd_content(pipe_fd[0]);
	close(pipe_fd[0]);
}
