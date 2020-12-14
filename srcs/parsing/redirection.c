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

int		ft_utils_count_redirection(t_data *data, int index, int i)
{
	int tmp;

	tmp = 0;
	if (data->cmd[index][i] == '>' && data->cmd[index][i + 1] == '>')
		tmp++;
	if (data->cmd[index][i] == '>' && data->cmd[index][i + 1] != '>'
		&& data->cmd[index][i - 1] != '>')
		tmp++;
	if (data->cmd[index][i] == '<' && data->cmd[index][i + 1] != '<'
		&& data->cmd[index][i - 1] != '<')
		tmp++;
	return (tmp);
}

void	count_redirection(t_data *data, int index, int i)
{
	int	red_nb;

	red_nb = 0;
	while (data->cmd[index][i] != '\0')
	{
		if (data->cmd[index][i] == '\'')
		{
			i++;
			while (data->cmd[index][i] != '\'' && data->cmd[index][i] != '\0')
				i++;
		}
		if (data->cmd[index][i] == '"')
		{
			i++;
			while (data->cmd[index][i] != '"' && data->cmd[index][i] != '\0')
				i++;
		}
		if (data->cmd[index][i] == '\0')
			break ;
		red_nb += ft_utils_count_redirection(data, index, i);
		i++;
	}
	data->tab[index].red_nb = red_nb;
}

char	*get_next_word(t_data *data, char *str, int index, int j)
{
	t_tmp	t;

	t.parg = NULL;
	while (str[index] != '\0')
	{
		if (str[index] != ' ')
		{
			t.itmp = 0;
			while (str[index + t.itmp] != ' ' && str[index + t.itmp] != '\0')
			{
				t.itmp_4 = j;
				gnw_2(data, str, index, &t);
				gnw_3(data, str, index, &t);
			}
			t.pctmp = list_to_pchar(t.parg);
			clear_list(&t.parg);
			j++;
			index += t.itmp - 1;
			return (t.pctmp);
		}
		index++;
	}
	return (NULL);
}

void	delete_next_word(t_data *data, char *str)
{
	t_tmp	t;

	t.itmp = 0;
	t.parg = NULL;
	t.itmp_4 = 0;
	while (str[t.itmp_4] != '\0')
	{
		if (str[t.itmp_4] != ' ')
		{
			t.itmp_2 = 0;
			while (str[t.itmp_4 + t.itmp_2] != ' '
			&& str[t.itmp_4 + t.itmp_2] != '\0')
			{
				delete_nw_utils(data, str, &t);
				delete_nw_2(data, str, &t);
			}
			t.pctmp_2 = ft_substr(str, t.itmp_4, t.itmp_2);
			t.pctmp = list_to_pchar(t.parg);
			clear_list(&t.parg);
			t.itmp++;
			t.itmp_4 += t.itmp_2 - 1;
			return ;
		}
		t.itmp_4++;
	}
}

void	ft_get_redirection(t_data *data, int index)
{
	t_tmp	t;

	t.itmp_2 = 0;
	t.itmp = 0;
	count_redirection(data, index, 0);
	data->tab[index].red = ft_malloc(sizeof(t_red)
	* (data->tab[index].red_nb + 1));
	if (data->tab[index].red == NULL)
		quit(0, "can't allocate redirection tab memory");
	while (data->cmd[index][t.itmp] != '\0')
	{
		gr_3(data, index, &t);
		if (data->cmd[index][t.itmp] == '\0')
			break ;
		gr_2(data, index, &t);
		if (data->cmd[index][t.itmp] == '<'
		&& data->cmd[index][t.itmp + 1] != '<'
				&& data->cmd[index][t.itmp - 1] != '<')
			get_redirection_utils(data, index, &t);
		t.itmp++;
	}
}
