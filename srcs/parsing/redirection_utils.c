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

void	delete_nw_3(t_data *data, char *str, t_tmp *t)
{
	if (str[t->itmp_4 + t->itmp_2] == '"')
	{
		t->itmp_2++;
		t->itmp_3 = t->itmp_4 + t->itmp_2;
		while (str[t->itmp_4 + t->itmp_2] != '"'
		&& str[t->itmp_4 + t->itmp_2])
		{
			str[t->itmp_4 + t->itmp_2] = ' ';
			t->itmp_2++;
		}
		t->pctmp_3 = ft_sub_env(data->env, ft_substr(str, t->itmp_3,
		t->itmp_4 + t->itmp_2 - t->itmp_3), 0);
		ft_lstadd_back_arg(&t->parg, ft_lstnew_arg(t->pctmp_3));
	}
}

void	delete_nw_utils(t_data *data, char *str, t_tmp *t)
{
	if (str[t->itmp_4 + t->itmp_2] == '\'')
	{
		t->itmp_2++;
		t->itmp_3 = t->itmp_4 + t->itmp_2;
		while (str[t->itmp_4 + t->itmp_2] != '\''
		&& str[t->itmp_4 + t->itmp_2])
		{
			str[t->itmp_4 + t->itmp_2] = ' ';
			t->itmp_2++;
		}
		t->pctmp_3 = ft_substr(str, t->itmp_3,
		t->itmp_4 + t->itmp_2 - t->itmp_3);
		ft_lstadd_back_arg(&t->parg, ft_lstnew_arg(t->pctmp_3));
		ft_free(t->pctmp_3);
	}
	delete_nw_3(data, str, t);
}

void	delete_nw_2(t_data *data, char *s, t_tmp *t)
{
	if (s[t->itmp_4 + t->itmp_2] != ' ' && s[t->itmp_4 + t->itmp_2]
	!= '"' && s[t->itmp_4 + t->itmp_2] != '\'')
	{
		t->itmp_3 = t->itmp_4 + t->itmp_2;
		while (s[t->itmp_4 + t->itmp_2] != ' ' && s[t->itmp_4 + t->itmp_2]
		&& s[t->itmp_4 + t->itmp_2] != '\'' && s[t->itmp_4 + t->itmp_2] != '"')
		{
			s[t->itmp_4 + t->itmp_2] = ' ';
			t->itmp_2++;
		}
		t->pctmp_3 = ft_sub_env(data->env, ft_substr(s, t->itmp_3,
		t->itmp_4 + t->itmp_2 - t->itmp_3), 0);
		ft_lstadd_back_arg(&t->parg, ft_lstnew_arg(t->pctmp_3));
		t->itmp_2--;
	}
	t->itmp_2++;
}

void	gnw_2(t_data *data, char *str, int index, t_tmp *t)
{
	if (str[index + t->itmp] == '\'')
	{
		t->itmp++;
		t->itmp_2 = index + t->itmp;
		while (str[index + t->itmp] != '\'' && str[index + t->itmp])
			t->itmp++;
		t->pctmp_2 = ft_substr(str, t->itmp_2, index + t->itmp - t->itmp_2);
		ft_lstadd_back_arg(&t->parg, ft_lstnew_arg(t->pctmp_2));
	}
	if (str[index + t->itmp] == '"')
	{
		t->itmp++;
		t->itmp_2 = index + t->itmp;
		while (str[index + t->itmp] != '"' && str[index + t->itmp])
			t->itmp++;
		t->pctmp_2 = ft_sub_env(data->env, ft_substr(str,
		t->itmp_2, index + t->itmp - t->itmp_2), 0);
		ft_lstadd_back_arg(&t->parg, ft_lstnew_arg(t->pctmp_2));
	}
}
