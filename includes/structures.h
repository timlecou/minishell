/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:37:45 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 08:43:57 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_arg
{
	char			*str;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_red
{
	int				type;
	int				fd;
	char			*content;
}					t_red;

typedef struct		s_cmd
{
	char			*name;
	char			**av;
	int				ac;
	int				red_nb;
	t_red			*red;
	char			*content;
	int				pipe_nb;
	char			***pipe_cmd;
	int				ret;
}					t_cmd;

typedef struct		s_data
{
	int				nb_cmd;
	char			**cmd;
	char			**envp;
	t_env			*env;
	t_cmd			*tab;
	int				status;
	int				last_ret;
}					t_data;

typedef struct		s_mem
{
	void			*addr;
	struct s_mem	*next;
}					t_mem;

typedef	struct		s_tmp
{
	int				itmp;
	int				itmp_2;
	int				itmp_3;
	int				itmp_4;
	int				itmp_5;
	int				itmp_6;
	char			*pctmp;
	char			*pctmp_2;
	char			*pctmp_3;
	char			*pctmp_4;
	t_arg			*parg;
	t_arg			*parg_1;
	t_arg			*parg_2;
	void			*p;
	void			*p_2;
}					t_tmp;

typedef	struct stat	t_stat;
#endif
