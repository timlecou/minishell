#include "minishell.h"

int		ft_len(char *str)
{
    int	i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

char	*ft_cut_begin(char *str)
{
    int		i;
    int		j;
    char	*tmp;

    i = 0;
    j = 0;
    while (str[j] != '\n' && str[j] != '\0')
        j++;
    if (!str)
        return (NULL);
    if (!(tmp = malloc(sizeof(char) * j + 1)))
        return (NULL);
    while (str[i] != '\n' && str[i] != '\0')
    {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char	*ft_cut(char *str) {
    char *res;
    int i;
    int j;

    i = 0;
    j = 0;
    if (!str)
        return (NULL);
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    i++;
    if (!(res = (char *) malloc(sizeof(char) * (ft_len(&str[i]) + 1))))
        return (NULL);
    while (str[i] != '\0') {
        res[j] = str[i];
        i++;
        j++;
    }
    res[j] = '\0';
    return (res);
}