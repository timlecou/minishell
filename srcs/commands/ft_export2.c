/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:54:33 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/13 22:54:34 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_utils_export(int *start)
{
	write(1, "\"", 1);
	*start = 1;
}

void	ft_utils_export_2(int *j, int *start)
{
	*j = 0;
	*start = 0;
	ft_putstr("declare -x ");
}
