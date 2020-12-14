/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:59:55 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/13 22:59:57 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_utils_count_pipe(t_data *data, int index, int i)
{
	int j;

	j = 0;
	while (data->cmd[index][i] != '\'' && data->cmd[index][i] != '\0')
		i++;
	return (j);
}

void	count_pipe(t_data *data, int index, int i)
{
	int	red_nb;

	red_nb = 0;
	while (data->cmd[index][i] != '\0' && data->cmd[index][i] != ' ')
		i++;
	while (data->cmd[index][i] != '\0')
	{
		if (data->cmd[index][i] == '\'')
		{
			i++;
			ft_utils_count_pipe(data, index, i);
		}
		if (data->cmd[index][i] == '"')
		{
			i++;
			while (data->cmd[index][i] != '"' && data->cmd[index][i] != '\0')
				i++;
		}
		if (data->cmd[index][i] == '\0')
			break ;
		if (data->cmd[index][i] == '|')
			red_nb++;
		i++;
	}
	data->tab[index].pipe_nb = red_nb;
}

void	ft_redirection(t_data *data, int index)
{
	int	i;

	i = 0;
	ft_get_redirection(data, index);
}

void	apply_redirection(t_data *data, int index)
{
	int		i;
	t_cmd	cmd;
	int		fd;

	i = 0;
	cmd = data->tab[index];
	while (i < cmd.red_nb)
	{
		if (cmd.red[i].type != L_REDIR)
		{
			write(cmd.red[i].fd, cmd.content, ft_strlen(cmd.content));
			close(fd);
		}
		i++;
	}
}
