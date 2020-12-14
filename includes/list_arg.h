/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_arg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:33:39 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 08:34:02 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ARG_H
# define LIST_ARG_H

void	ft_lstadd_back_arg(t_arg **list, t_arg *new);
t_arg	*ft_lstnew_arg(char *str);
void	print_list(t_arg *arg);
char	*list_to_pchar(t_arg *arg);
void	clear_list(t_arg **arg);

#endif
