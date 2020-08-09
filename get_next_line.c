#include "minishell.h"

int		is_nl(char *str)
{
    int	i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

int		ft_all_cut(char **res, char **line, int ret)
{
    char	*ptr;

    ptr = NULL;
    if (is_nl(*res))
    {
        *line = ft_cut_begin(*res);
        ptr = *res;
        *res = ft_cut(*res);
        free(ptr);
    }
    else if (!is_nl(*res) && ret == 0)
    {
        *line = ft_strdup(*res);
        free(*res);
        *res = NULL;
        return (0);
    }
    return (1);
}

int		ft_ret(char **res, int fd)
{
    int		ret;
    char	tmp[BUFFER_SIZE + 1];
    char	*ptr;

    ret = 0;
    ptr = NULL;
    while (!is_nl(*res) && (ret = read(fd, tmp, BUFFER_SIZE)) != 0)
    {
        if (ret == -1)
            return (-1);
        tmp[ret] = '\0';
        ptr = *res;
        *res = ft_strjoin(*res, tmp);
        free(ptr);
    }
    return (ret);
}

int		get_next_line(int fd, char **line)
{
    static char	*res = NULL;
    int			ret;
    char		*ptr;

    ptr = NULL;
    if (BUFFER_SIZE <= 0 || fd < 0 || !line)
        return (-1);
    ret = ft_ret(&res, fd);
    if (ret == -1)
        return (-1);
    write(1, "ok1\n", 4);
    if (res)
    {
        if (ft_all_cut(&res, line, ret) == 0)
            return (0);
    }
    else
    {
        *line = ft_strdup("");
        return (0);
    }
    return (1);
}
