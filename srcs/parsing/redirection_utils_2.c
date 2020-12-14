/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:13:15 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/13 23:15:45 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	gnw_3(t_data *data, char *str, int index, t_tmp *t)
{
	if (str[index + t->itmp] != ' ' && str[index + t->itmp]
	!= '"' && str[index + t->itmp] != '\'')
	{
		t->itmp_2 = index + t->itmp;
		while (str[index + t->itmp] != ' ' && str[index + t->itmp]
				&& str[index + t->itmp] != '\'' && str[index + t->itmp] != '"')
			t->itmp++;
		t->pctmp_2 = ft_sub_env(data->env, ft_substr(str,
		t->itmp_2, index + t->itmp - t->itmp_2), 0);
		ft_lstadd_back_arg(&t->parg, ft_lstnew_arg(t->pctmp_2));
		t->itmp--;
	}
	t->itmp++;
}

void	gr_2(t_data *data, int index, t_tmp *t)
{
	if (data->cmd[index][t->itmp] == '>'
		&& data->cmd[index][t->itmp + 1] == '>')
	{
		data->cmd[index][t->itmp] = ' ';
		data->cmd[index][t->itmp + 1] = ' ';
		data->tab[index].red[t->itmp_2].fd = open(get_next_word(data,
		&data->cmd[index][t->itmp + 2], 0, 0), 1090, S_IRUSR | S_IWUSR);
		data->tab[index].red[t->itmp_2].type = R_REDIR;
		delete_next_word(data, &data->cmd[index][t->itmp + 1]);
		t->itmp_2++;
	}
	if (data->cmd[index][t->itmp] == '>' && data->cmd[index][t->itmp + 1] != '>'
			&& data->cmd[index][t->itmp - 1] != '>')
	{
		data->cmd[index][t->itmp] = ' ';
		data->tab[index].red[t->itmp_2].fd = open(get_next_word(data,
		&data->cmd[index][t->itmp + 1], 0, 0), 578, S_IRUSR | S_IWUSR);
		data->tab[index].red[t->itmp_2].type = DR_REDIR;
		delete_next_word(data, &data->cmd[index][t->itmp + 1]);
		t->itmp_2++;
	}
}

void	gr_3(t_data *data, int index, t_tmp *t)
{
	if (data->cmd[index][t->itmp] == '\'')
	{
		t->itmp++;
		while (data->cmd[index][t->itmp] != '\''
				&& data->cmd[index][t->itmp] != '\0')
			t->itmp++;
	}
	if (data->cmd[index][t->itmp] == '"')
	{
		t->itmp++;
		while (data->cmd[index][t->itmp] != '"'
				&& data->cmd[index][t->itmp] != '\0')
			t->itmp++;
	}
}

void	get_redirection_utils(t_data *data, int index, t_tmp *t)
{
	data->cmd[index][t->itmp] = ' ';
	data->tab[index].red[t->itmp_2].fd = open(get_next_word(
	data, &data->cmd[index][t->itmp + 1], 0, 0), O_RDONLY);
	data->tab[index].red[t->itmp_2].type = L_REDIR;
	data->tab[index].red[t->itmp_2].content = get_fd_content(
	data->tab[index].red[t->itmp_2].fd);
	delete_next_word(data, &data->cmd[index][t->itmp + 1]);
	t->itmp_2++;
}
