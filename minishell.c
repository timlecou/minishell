/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:37:09 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 08:37:25 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_env	*g_env;
t_mem	*g_mem;
int		g_is_in_cmd = 0;
t_data	*g_data;

void	ft_do_cmd(t_data *data, int index)
{
	int	pid;
	int	status;
	int	pipe_fd[2];

	if (is_perso_cmd(data->tab[index].name))
	{
		ft_utils_exec2(data, index, pipe_fd);
		pid = fork();
		if (pid == -1)
			return ;
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			kill(pid, SIGTERM);
			data->tab[index].ret = WEXITSTATUS(status);
			if (data->tab[index].red_nb > 0)
				ft_utils_exec3(data, index, pipe_fd);
		}
		else
			ft_utils_exec(data, index, pipe_fd);
	}
	else
		ft_other_cmd(data, index);
}

void	ft_utils_manage_line(t_data *data, int i)
{
	char	*ret_str;

	ft_redirection(data, i);
	ft_parsing(data, i);
	ft_do_cmd(data, i);
	apply_redirection(data, i);
	data->last_ret = data->tab[i].ret;
	ret_str = ft_itoa(data->last_ret);
	edit_env_value(data->env, "?", ret_str);
}

int		ft_manage_line(char *line, t_env *env, char **envp)
{
	t_data	data;
	int		i;
	int		j;
	int		ret;

	i = 0;
	data = init_data_struct();
	g_data = &data;
	data.env = env;
	data.cmd = ft_split_args(line, ';');
	data.envp = envp;
	data.nb_cmd = ft_count_commands(line, ';');
	if (!(data.tab = (t_cmd*)ft_malloc(sizeof(t_cmd) * (data.nb_cmd + 1))))
		quit(0, "fail to allocate command array");
	while (i < data.nb_cmd)
	{
		j = ft_pipe(&data, data.cmd[i]);
		if (j == 0 && contains_letter(data.cmd[i]))
			ft_utils_manage_line(&data, i);
		i++;
	}
	ret = data.last_ret;
	return (ret);
}

void	ft_minishell(char **envp)
{
	char	*line;
	t_env	*env;
	int		ret;

	env = ft_fill_env_list(envp);
	line = NULL;
	g_env = env;
	ft_print_begin(env);
	signal(SIGINT, sig_c);
	signal(SIGQUIT, sig_bs);
	while (get_next_line(0, &line) > 0)
	{
		g_is_in_cmd = 1;
		ret = ft_manage_line(line, env, envp);
		ft_free(line);
		line = NULL;
		if (ret == 0)
			ft_putstr("\033[0;34m");
		else
			ft_putstr("\033[0;31m");
		ft_putstr(get_env(env, "PWD"));
		ft_putstr("\033[0;33m ➜ \033[0;0m");
		g_is_in_cmd = 0;
	}
	ft_lstclear(&env, ft_del_elem);
}

int		main(int ac, char **av, char **envp)
{
	int	i;

	i = 0;
	g_mem = malloc(sizeof(t_mem));
	g_mem->next = NULL;
	g_mem->addr = NULL;
	if (ac > 1)
	{
		ft_putstr("Ignore param :");
		while (++i < ac)
			ft_putstr(ft_strjoin("	- ",
			ft_strjoin(av[i], "\n")));
	}
	ft_minishell(envp);
	return (0);
}
