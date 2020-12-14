/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_other_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:01:35 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 10:02:47 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_utils_other_cmd(t_data *data, int index, int pipe_fd[2], int pid)
{
	if (exist_l_redir(data, index))
	{
		if (!exist_r_redir(data, index))
			close(pipe_fd[0]);
		write(pipe_fd[1], get_l_redir_content(data, index),
		ft_strlen(get_l_redir_content(data, index)));
		close(pipe_fd[1]);
	}
	waitpid(pid, &data->status, 0);
	if (WIFSIGNALED(data->status) && WTERMSIG(data->status) == SIGINT)
		data->tab[index].ret = 130;
	else if (WIFSIGNALED(data->status) && WTERMSIG(data->status) == SIGQUIT)
		data->tab[index].ret = 131;
	else
		data->tab[index].ret = WEXITSTATUS(data->status);
	if (exist_r_redir(data, index))
	{
		close(pipe_fd[1]);
		data->tab[index].content = get_fd_content(pipe_fd[0]);
		close(pipe_fd[0]);
	}
}

void	ft_utils_other_cmd2(t_data *d, int index, int pipe_fd[2], char ***env)
{
	if (exist_l_redir(d, index))
	{
		if (!exist_r_redir(d, index))
			close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
	}
	if (exist_r_redir(d, index))
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
	}
	*env = ft_list_to_char(d->env);
}

void	ft_utils_other_cmd3(char **path_dir, int index,
				t_data *data, char *file)
{
	int i;

	i = 0;
	while (path_dir[i])
	{
		if (file_exist(path_dir[i], data->tab[index].name, &file) == 1)
		{
			exec_file(data, index, file);
			return ;
		}
		i++;
	}
	ft_putstr("Error: ");
	ft_putstr(data->tab[index].name);
	ft_putstr(" not found\n");
	data->tab[index].ret = 127;
}

void	ft_utils_other_cmd4(t_data *data, char **file, char **str, int index)
{
	*file = ft_substr(data->tab[index].name,
	get_last_pos(data->tab[index].name, '/') + 1,
	ft_strlen(data->tab[index].name) -
	get_last_pos(data->tab[index].name, '/'));
	*str = replace_str(data->tab[index].name, *file, "");
}
