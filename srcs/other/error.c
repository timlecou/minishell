/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:37:09 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 08:37:25 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	quit(int state, char *str)
{
	ft_putstr(str);
	free_mem();
	exit(state);
}

void	ft_quit(int code)
{
	free_mem();
	exit(code);
}

void	ft_command_nf(char *str)
{
	ft_putstr("minishell: ");
	ft_putstr(str);
	ft_putstr(": command not found\n");
}
