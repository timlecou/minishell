/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:21:16 by timlecou          #+#    #+#             */
/*   Updated: 2020/04/15 16:47:40 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd(t_data *data, int index)
{
	char	new_pwd[2048];
	char	ex_pwd[2048];

	if (data->tab[index].ac > 2)
	{
		ft_putstr("cd : Error: too many arguments for cd !\n");
		data->tab[index].ret = 1;
		return ;
	}
	getcwd(ex_pwd, 2048);
	if (chdir(data->tab[index].av[1]) == -1)
	{
		ft_putstr("cd : Error cannot open dir '");
		ft_putstr(data->tab[index].av[1]);
		ft_putstr("'.\n");
		data->tab[index].ret = 1;
		return ;
	}
	getcwd(new_pwd, 2048);
	edit_env_value(data->env, "PWD", ft_strdup(new_pwd));
	edit_env_value(data->env, "OLDPWD", ft_strdup(ex_pwd));
	data->tab[index].ret = 0;
}
