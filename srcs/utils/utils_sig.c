/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:03:04 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 10:03:38 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int		g_is_in_cmd;
extern t_env	*g_env;
extern t_data	*g_data;

void	sig_c(int i)
{
	write(1, "\n", 1);
	if (g_is_in_cmd == 0 && i > g_is_in_cmd)
	{
		ft_putstr("\033[0;34m");
		ft_putstr(get_env(g_env, "PWD"));
		ft_putstr("\033[0;33m ➜ \033[0;0m");
	}
	edit_env_value(g_env, "?", "130");
}

void	sig_bs(int i)
{
	if (g_is_in_cmd && i > g_is_in_cmd)
		ft_putstr("Quit core dumped\n");
}

void	ft_print_begin(t_env *env)
{
	ft_putstr("\033[0;35m🚨Bienvenu dans minishell !🚨\n\033[0;0m");
	ft_putstr("\033[0;34m");
	ft_putstr(get_env(env, "PWD"));
	ft_putstr("\033[0;33m ➜ \033[0;0m");
}
