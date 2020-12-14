/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:09:07 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/16 18:46:49 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_utils_arg_2(char *str, int index, t_arg **av, t_tmp *t)
{
	t_data	*data;

	data = t->p;
	if (str[index + t->itmp_2] == '\'' && str[index + t->itmp_2 - 1] != '\\')
	{
		ft_utils_args2(str, &t->itmp_2, &t->itmp, index);
		t->pctmp = ft_substr(str, t->itmp, index + t->itmp_2 - t->itmp);
		if (ft_has_bs(t->pctmp))
			t->pctmp = test(t->pctmp);
		ft_lstadd_back_arg(av, ft_lstnew_arg(t->pctmp));
	}
	if (str[index + t->itmp_2] == '"' && str[index + t->itmp_2 - 1] != '\\')
	{
		ft_utils_args3(str, &t->itmp_2, &t->itmp, index);
		t->pctmp = ft_sub_env(data->env, ft_substr(str,
		t->itmp, index + t->itmp_2 - t->itmp), 0);
		if (ft_has_bs(t->pctmp))
			t->pctmp = test(t->pctmp);
		ft_lstadd_back_arg(av, ft_lstnew_arg(t->pctmp));
	}
}

void	ft_parsing(t_data *data, int index)
{
	char	*str;

	data->tab[index].ac = ft_count_args(data->cmd[index], 0);
	str = data->cmd[index];
	data->tab[index].av = ft_get_args(data, str, 0, data->tab[index].ac + 1);
	data->tab[index].name = data->tab[index].av[0];
}

char	**ft_get_args(t_data *data, char *str, int index, int ac)
{
	int		i;
	int		j;
	char	**res;
	t_arg	*av;

	j = 0;
	av = NULL;
	if (!(res = (char**)ft_malloc(sizeof(char*) * ac)))
		return (NULL);
	while (str[index] != '\0')
	{
		if (str[index] != ' ' && str[index] != '\t')
		{
			i = ft_utils_args(str, index, &av, data);
			res[j] = list_to_pchar(av);
			clear_list(&av);
			j++;
			index += i - 1;
		}
		index++;
	}
	res[j] = 0;
	return (res);
}

void	ft_utils_arg5(char *str, int index, t_tmp *t)
{
	t->itmp_3 = 0;
	while (str[index + t->itmp_2] != '\0')
	{
		if (str[index + t->itmp_2] == ' ' || str[index + t->itmp_2] == '\t')
			break ;
		if ((str[index + t->itmp_2] == '\'' || str[index + t->itmp_2]
		== '"') && str[index + t->itmp_2 - 1] != '\\')
		{
			break ;
		}
		t->itmp_2++;
	}
}

int		ft_utils_args(char *str, int index, t_arg **av, t_data *data)
{
	t_tmp	t;

	t.itmp_2 = 0;
	while (str[index + t.itmp_2] != ' '
			&& index + t.itmp_2 < (int)ft_strlen(str)
			&& str[index + t.itmp_2] != '\t')
	{
		t.p = data;
		ft_utils_arg_2(str, index, av, &t);
		if (str[index + t.itmp_2] != ' ' && str[index + t.itmp_2] != '"'
			&& str[index + t.itmp_2] != '\'' && str[index + t.itmp_2] != '\t')
		{
			t.itmp = index + t.itmp_2;
			ft_utils_arg5(str, index, &t);
			t.pctmp = ft_sub_env(data->env, ft_substr(str,
			t.itmp, index + t.itmp_2 - t.itmp), 0);
			if (ft_has_bs(t.pctmp))
				t.pctmp = test(t.pctmp);
			replace_wave(&t.pctmp, data);
			ft_lstadd_back_arg(av, ft_lstnew_arg(t.pctmp));
			t.itmp_2--;
		}
		t.itmp_2++;
	}
	return (t.itmp_2);
}
