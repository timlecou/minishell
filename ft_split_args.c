/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:21:16 by timlecou          #+#    #+#             */
/*   Updated: 2020/04/15 16:47:40 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_count_commands(const char *str, char c)
{
    int	i;
    int	count;

    i = 0;
    count = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\'')
        {
            i++;
            while (str[i] != '\'')
                i++;
        }
        if (str[i] == '\"')
        {
            i++;
            while (str[i] != '\"')
                i++;
        }
        if ((str[i] != c && i == 0) || (str[i] != c && str[i - 1] == c))
            count++;
        i++;
    }
    return (count);
}

char	**ft_split_args(const char *s, char c)
{
    char	**res;
    int		index;
    int		i;
    int		j;

    index = 0;
    i = 0;
    if (!s || !(res = (char**)malloc(sizeof(char*) * (ft_count_commands(s, c) + 1))))
        return (NULL);
    while (s[i] != '\0')
    {
        j = 0;
        while (s[i + j] != c && s[i + j] != '\0')
        {
            if (s[i + j] == '\'')
            {
                j++;
                while (s[i + j] != '\'')
                    j++;
            }
            if (s[i + j] == '\"')
            {
                j++;
                while (s[i + j] != '\"')
                    j++;
            }
            j++;
        }
        if (j > 0)
        {
            res[index] = ft_substr(s, i, j);
            index++;
            i += j - 1;
        }
        i++;
    }
    res[index] = 0;
    return (res);
}
