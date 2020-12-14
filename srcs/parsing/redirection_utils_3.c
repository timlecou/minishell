/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:00:10 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/13 23:07:43 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		get_last_r_redir(t_data *data, int index)
{
	int		i;
	t_cmd	cmd;
	int		fd;

	i = 0;
	cmd = data->tab[index];
	fd = 0;
	while (i < cmd.red_nb)
	{
		if (cmd.red[i].type != L_REDIR)
			fd = cmd.red[i].fd;
		i++;
	}
	return (fd);
}

void	apply_redirection(t_data *data, int index)
{
	int		i;
	t_cmd	cmd;

	i = 0;
	cmd = data->tab[index];
	while (i < cmd.red_nb)
	{
		if (cmd.red[i].fd == get_last_r_redir(data, index))
		{
			write(get_last_r_redir(data, index),
			cmd.content, ft_strlen(cmd.content));
			close(get_last_r_redir(data, index));
		}
		i++;
	}
}

int		exist_r_redir(t_data *data, int index)
{
	int	i;

	i = 0;
	while (i < data->tab[index].red_nb)
	{
		if (data->tab[index].red[i].type == R_REDIR
			|| data->tab[index].red[i].type == DR_REDIR)
			return (1);
		i++;
	}
	return (0);
}

int		exist_l_redir(t_data *data, int index)
{
	int	i;

	i = 0;
	while (i < data->tab[index].red_nb)
	{
		if (data->tab[index].red[i].type == L_REDIR)
			return (1);
		i++;
	}
	return (0);
}

char	*get_l_redir_content(t_data *data, int index)
{
	int	i;

	i = data->tab[index].red_nb - 1;
	while (i >= 0)
	{
		if (data->tab[index].red[i].type == L_REDIR)
			return (data->tab[index].red[i].content);
		i--;
	}
	return (NULL);
}
