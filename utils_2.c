#include "minishell.h"

char	*ft_get_env(t_data *data, char *str, int i)
{
	int	j;
	int	index;
	t_env	*tmp;

	j = 0;
	index = 0;
	tmp = data->env;
	i++;
	while (str[i + j] != ' ' && str[i + j] != '\'' && str[i + j] != '\"' && str[i + j] != '$' && str[i + j] != '\0')
		j++;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(&str[i], tmp->var, j) == 0)
			return (ft_strdup(&tmp->var[j + 1]));
		tmp = tmp->next;
	}
	return ("");
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char    **ft_get_args(t_data *data, char *str, int index, int ac)
{
    char    **res;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (!(res = (char**)malloc(sizeof(char*) * ac)))
        return (NULL);
    while (str[index] != '\0')
    {
        i = 0;
        if (str[index] != ' ' && str[index] != '\'' && str[index] != '\"' && str[index] != '$')
        {
            while (str[index + i] != ' ' && str[index + i] != '\'' && str[index + i] != '\"' && str[index + i] != '$' && str[index + i] != '\0')
                i++;
            res[j] = ft_substr(str, index, i);
            j++;
            index += i;
            i = 0;
        }
        if (str[index] == '\'')
        {
            index++;
            while (str[index + i] != '\'' && str[index + i] != '\0')
                i++;
            res[j] = ft_substr(str, index, i);
            j++;
            index += i;
            i = 0;
        }
        if (str[index] == '\"')
        {
            index++;
            while (str[index + i] != '\"' && str[index + i] != '\0')
                i++;
            res[j] = ft_substr(str, index, i);
            j++;
            index += i;
            i = 0;
        }
        if (str[index] == '$')
        {
            res[j] = ft_get_env(data, str, index);
            j++;
            index++;
            while (str[index] != ' ' && str[index] != '\'' && str[index] != '$'
            && str[index] != '\"' && str[index] != '\0')
                index++;
            index--;
        }
        index++;
    }
    res[j] = 0;
    return (res);
}