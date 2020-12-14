/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:36:20 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 08:36:41 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 2048
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "get_next_line.h"
# include "structures.h"
# include "libft.h"
# include "list_env.h"
# include "utils.h"
# include "redirection.h"
# include "define.h"
# include "list_arg.h"
# define IN 0
# define OUT 1

void	ft_echo(t_data *data, int index);
void	ft_pwd(t_data *data, int index);
void	ft_export(t_data *data, int index);
void	ft_env(t_data *data, int index);
void	ft_cd(t_data *data, int index);
void	ft_unset(t_data *data, int index);
void	ft_other_cmd(t_data *data, int index);
#endif
