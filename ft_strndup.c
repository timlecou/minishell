/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:21:35 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/07 18:01:33 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_slen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strndup(const char *str, int len)
{
	int		i;
	int		nb;
	char	*res;

	i = 0;
	nb = (len > ft_slen(str)) ? ft_slen(str) : len;
	if (!(res = (char*)malloc(sizeof(char) * nb + 1)))
		return (NULL);
	while (str[i] != '\0' && len)
	{
		res[i] = str[i];
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
