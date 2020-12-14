/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:11:57 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/13 23:11:59 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_utils_pipe2(int p[3][2], char io[2][2048], int is, t_data *tmp_data)
{
	tmp_data->last_ret = 0;
	close(p[0][1]);
	is = read(p[0][0], io[IN], 2048);
	close(p[0][0]);
	io[IN][is] = '\0';
	pipe(p[2]);
	dup2(p[2][0], 0);
	close(p[2][0]);
	write(p[2][1], io[IN], is);
	close(p[2][1]);
	dup2(p[1][1], 1);
}

void	ft_utils_pipe3(int p[3][2], char io[2][2048], int pid, t_data *tmp_data)
{
	close(p[0][0]);
	write(p[0][1], io[IN], ft_strlen(io[IN]));
	close(p[0][1]);
	waitpid(pid, &tmp_data->status, 0);
	close(p[1][1]);
}

void	ft_utils_pipe(int pipe_fd[3][2], char io[2][2048], t_data *data, int j)
{
	int		pid;
	int		in_size;
	int		out_size;

	pipe(pipe_fd[0]);
	pipe(pipe_fd[1]);
	in_size = 0;
	pid = fork();
	if (pid == 0)
	{
		ft_utils_pipe2(pipe_fd, io, in_size, data);
		ft_redirection(data, j);
		ft_parsing(data, j);
		ft_do_cmd(data, j);
		apply_redirection(data, j);
		ft_quit(data->tab[j].ret);
	}
	else
	{
		ft_utils_pipe3(pipe_fd, io, pid, data);
		out_size = read(pipe_fd[1][0], io[OUT], 2048);
		io[OUT][out_size] = '\0';
	}
	ft_strcpy(io[IN], io[OUT]);
}

int		ft_pipe(t_data *data, char *line)
{
	t_data	tmp_data;
	int		j;
	int		pipe_fd[3][2];
	char	io[2][2048];

	j = 0;
	tmp_data = *data;
	tmp_data.cmd = ft_split_args(line, '|');
	tmp_data.nb_cmd = ft_count_commands(line, '|');
	io[IN][0] = '\0';
	if (tmp_data.nb_cmd == 1)
		return (0);
	if (!(tmp_data.tab = ft_malloc(sizeof(t_cmd) * (tmp_data.nb_cmd + 1))))
		quit(0, "fail to allocate command array");
	while (j < tmp_data.nb_cmd)
	{
		ft_utils_pipe(pipe_fd, io, &tmp_data, j);
		j++;
	}
	ft_putstr(io[OUT]);
	data->last_ret = WEXITSTATUS(tmp_data.status);
	return (j);
}
