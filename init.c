#include "minishell.h"

char    *ft_inc_shlvl(char *str)
{
    int     i;
    char    *ret;
    char    *tmp;

    i = 0;
    tmp = NULL;
    ret = NULL;
    if (ft_strlen(str) > 6)
        i = ft_atoi(&str[6]);
    tmp = ft_itoa(i + 1);
    ret = ft_strjoin("SHLVL=", tmp);
    free(tmp);
    return (ret);
}

t_data  init_data_struct(void)
{
    t_data  data;

    data.nb_cmd = 0;
    data.cmd = NULL;
    data.env = NULL;
    data.envp = NULL;
    return (data);
}

t_cmd  init_cmd_struct(void)
{
    t_cmd   cmd;

    cmd.is_op = 0;
    cmd.name = NULL;
    cmd.op = NULL;
    cmd.av = NULL;
    cmd.ac = 0;
    return (cmd);
}
