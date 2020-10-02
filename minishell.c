

#include "minishell.h"

void    ft_manage_line(char *line, t_env *env, char **envp)
{
    t_data  data;
    int     i;

    i = 0;
    data = init_data_struct();
    data.env = env;
    data.cmd = ft_split(line, ';');
    data.envp = envp;
    data.nb_cmd = ft_count_commands(line, ';');
    if (!(data.tab = (t_cmd*)malloc(sizeof(t_cmd) * (data.nb_cmd + 1))))
        quit(0, "fail to allocate command array");
    while (i < data.nb_cmd)
    {
	    ft_parsing(&data, i);
	    ft_do_cmd(&data, i);
        i++;
    }
    ft_free_data_struct(&data);
}

void    ft_minishell(char **envp)
{
    char    *line;
    t_env   *env;

    env = ft_fill_env_list(envp);
    line = NULL;
    ft_putstr("\033[0;34m🚨Bienvenu dans minishell !🚨\n\033[0;0m");
    ft_putstr("\033[0;33m🁡➜ \033[0;0m");
    while ((get_next_line(0, &line)) > 0)
    {
        ft_manage_line(line, env, envp);
        free(line);
        line = NULL;
        ft_putstr("\033[0;33m🁡➜ \033[0;0m");
    }
    ft_lstclear(&env, ft_del_elem);
}

int     main(int ac, char **av, char **envp)
{
    if (ac == 1)
	    ft_minishell(envp);
    return (0);
}

