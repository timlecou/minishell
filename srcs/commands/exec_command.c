/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:54:42 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 09:08:15 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_find_path(char *cmd)
{
	struct stat	buf;

	if (stat(cmd, &buf) == -1)
		return (0);
	return (S_ISREG(buf.st_mode));
}

int		file_exist(char *path, char *name, char **file)
{
	char	*file_path;
	char	*tmp;
	t_stat	st;

	if (name[0] != '/')
	{
		if (name[0] == '~')
			name = &name[1];
		if (path[ft_strlen(path) - 1] != '/')
			file_path = ft_strjoin(path, "/");
		else
			file_path = ft_strdup(path);
		tmp = file_path;
		file_path = ft_strjoin(file_path, name);
		ft_free(tmp);
	}
	else
		file_path = ft_strdup(name);
	*file = file_path;
	if (stat(file_path, &st) == -1)
		return (-1);
	return (S_ISREG(st.st_mode) == 1);
}

int		exec_file(t_data *data, int index, char *file)
{
	int		pid;
	int		pipe_fd[2];
	char	**env;

	pipe(pipe_fd);
	pid = fork();
	if ((env = ft_list_to_char(data->env)) && pid == -1)
		return (-1);
	else if (pid > 0)
		ft_utils_other_cmd(data, index, pipe_fd, pid);
	else
	{
		ft_utils_other_cmd2(data, index, pipe_fd, &env);
		if (execve(file, data->tab[index].av, env) == -1)
			return (-1);
	}
	return (0);
}

int		ft_utils_other_cmd5(t_data *data, char *file, char *str, int index)
{
	ft_utils_other_cmd4(data, &file, &str, index);
	if (file_exist(str, file, &file) != -1)
	{
		exec_file(data, index, file);
		return (0);
	}
	return (1);
}

void	ft_other_cmd(t_data *data, int index)
{
	char	*path;
	char	**path_dir;
	char	*file;
	char	*str;

	path = get_env_value(data->env, "PATH");
	path_dir = ft_split(path, ':');
	if ((str = NULL) == NULL && path_dir == NULL)
		return ;
	if ((ft_strncmp(data->tab[index].name, "./", 2) == 0
		|| ft_strncmp(data->tab[index].name, "../", 3) == 0) && file_exist(
		get_env_value(data->env, "PWD"), data->tab[index].name, &file) != -1)
	{
		exec_file(data, index, file);
		return ;
	}
	if (ft_strncmp(data->tab[index].name, "/", 1) == 0)
		if (!ft_utils_other_cmd5(data, file, str, index))
			return ;
	if (ft_strncmp(data->tab[index].name, "~", 1) == 0 && file_exist(
		get_env_value(data->env, "HOME"), data->tab[index].name, &file) != -1
		&& exec_file(data, index, file) != -1)
		return ;
	ft_utils_other_cmd3(path_dir, index, data, file);
}
