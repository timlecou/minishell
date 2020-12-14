/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:35:32 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 08:35:57 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ENV_H
# define LIST_ENV_H
# include "structures.h"

t_env	*ft_fill_env_list(char **envp);
char	*ft_sub_env(t_env *env, char *str, int i);
void	ft_lstclear(t_env **env, void (*ft_del_elem)(t_env *));
char	**ft_list_to_char(t_env *env);
char	*ft_get_env_name(char *str);
char	*ft_get_env_value(char *str);
t_env	*ft_lstnew(char *name, char *value);
void	ft_lstadd_back(t_env **lst, t_env *new);
t_data	init_data_struct(void);
t_cmd	init_cmd_struct(void);
void	ft_remove_elem_from_list(t_env **env, char *name);
void	ft_free_data_struct(t_data *data);
char	*ft_get_env(t_data *data, char *str, int index);
void	ft_sort_env_tab(char **tab, int i);
char	*ft_inc_shlvl(char *str);
char	*get_env_value(t_env *env, char *name);
void	edit_env_value(t_env *env, char *name, char *new);
void	set_env(t_env **env, char *name, char *val);
int		ft_is_set(t_env *env, char *name);
int		env_exists(t_env *env, char *name);

#endif
