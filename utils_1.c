

#include "minishell.h"

int     ft_count_args(char *str, int index)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (str[index] != '\0')
    {
        if (str[index] != ' ' && str[index] != '\'' && str[index] != '\"' && str[index] != '$')
        {
            count++;
            while (str[index + i] != ' ' && str[index + i] != '\'' && str[index + i] != '\"' && str[index] != '$' && str[index + i] != '\0')
                i++;
            index += i;
            i = 0;
        }
        if (str[index] == '\'')
        {
            index++;
            count++;
            while (str[index + i] != '\'' && str[index + i] != '\0')
                i++;
            index += i;
            i = 0;
        }
        if (str[index] == '\"')
        {
            index++;
            count++;
            while (str[index + i] != '\"' && str[index + i] != '\0')
                i++;
            index += i;
            i = 0;
        }
        if (str[index] == '$')
        {
            count++;
            index++;
            while (str[index] != ' ' && str[index] != '\'' && str[index] != '$'
            && str[index] != '\"' && str[index] != '\0')
                index++;
            index--;
        }
        index++;
    }
    return (count);
}

int	ft_atoi(const char *str)
{
    int	i;
    int	res;
    int	signe;

    i = 0;
    res = 0;
    signe = 1;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
           || str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signe = -1;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * signe);
}


int     ft_get_str(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '"')
            return (i);
        i++;
    }
    return (0);
}

int     ft_get_word_size(char *line)
{
    int    i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == ' ')
            return (i);
        i++;
    }
    return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}




















