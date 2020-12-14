/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <timlecou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:29:28 by timlecou          #+#    #+#             */
/*   Updated: 2020/11/14 08:30:03 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char			*ft_strcpy(char *dest, char *src);
char			*ft_getline(char *str);
char			*ft_getrest(char *str, int *empty_rest);

struct			s_gnl
{
	char	*rest;
	int		byte_nb;
};
typedef	struct s_gnl	t_gnl;

#endif
