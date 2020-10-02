/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:57:44 by tsarafia          #+#    #+#             */
/*   Updated: 2019/11/19 17:15:19 by tsarafia         ###   ########.fr       */
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
