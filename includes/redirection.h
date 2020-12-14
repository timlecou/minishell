/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:37:09 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 08:37:25 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

void	ft_redirection(t_data *data, int index);
void	apply_redirection(t_data *data, int index);
int		exist_r_redir(t_data *data, int index);
int		exist_l_redir(t_data *data, int index);
char	*get_l_redir_content(t_data *data, int index);
void	delete_next_word(t_data *data, char *str);
void	delete_nw_utils(t_data *data, char *str, t_tmp *t);
void	delete_nw_2(t_data *data, char *str, t_tmp *t);
char	*get_next_word(t_data *data, char *str, int index, int j);
void	gnw_2(t_data *data, char *str, int index, t_tmp *tmp);
void	gnw_3(t_data *data, char *str, int index, t_tmp *t);
void	gr_2(t_data *data, int index, t_tmp *t);
void	gr_3(t_data *data, int index, t_tmp *t);
void	ft_utils_arg_2(char *s, int i, t_arg **av, t_tmp *t);
void	ft_utils_args2(char *str, int *d, int *k, int index);
void	ft_utils_args3(char *str, int *d, int *k, int index);
void	get_redirection_utils(t_data *data, int index, t_tmp *t);
void	ft_get_redirection(t_data *data, int index);

#endif
