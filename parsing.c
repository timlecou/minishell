
#include "minishell.h"

char    *get_env(t_env *env, char *var)
{
    t_env   *tmp;
    int     len;

    tmp = env;
    len = 0;
    while (tmp != NULL)
    {
        len = ft_strlen(var);
        if (ft_strncmp(tmp->var, var, ft_strlen(var)) == 0)
            return (ft_substr(tmp->var, len + 1, ft_strlen(tmp->var) - len));
        tmp = tmp->next;
    }
    return (NULL);
}

int     ft_find_path(char *cmd)
{
    struct stat buf;

    if (stat(cmd, &buf) == -1)
        return (0);
    return (S_ISREG(buf.st_mode));
}

char    *ft_try_path(char *cmd, char *paths)
{
    char    *res;
    char    *tmp;
    char    *tmp2;

    if (paths)
    {
        paths = ft_strjoin(paths, "/");
        tmp = paths;
        res = ft_strjoin(paths, cmd);
        free(tmp);
    }
    return (res);
}

void	ft_command_nf(char *str)
{
	ft_putstr("minishell: ");
	ft_putstr(str);
	ft_putstr(": command not found\n");
}

void    ft_other_cmd(t_data *data, int index)
{
    char    **paths;
    pid_t   pid;
    int     i;
    char    *path;
    char    *tmp;

    i = 0;
    if (!ft_find_path(data->cmd[index]) || ft_strncmp(data->cmd[index], "./", 2))
    {
        tmp = get_env(data->env, "PATH");
        paths = ft_split(tmp, ':');
        free(tmp);
        tmp = NULL;
        while (paths[i])
        {
            path = ft_try_path(data->tab[index].name, paths[i]);
            if (ft_find_path(path))
                break;
            free(path);
            path = NULL;
            i++;
        }
        ft_free_splitted_array(paths);
    }
    if ((pid = fork()) == -1)
        perror("fork");
    if (pid == 0)
    {
        if (execve(path, data->tab[index].av, data->envp) == -1)
            ft_command_nf(data->tab[index].name);
    }
    else if (pid > 0)
        wait(&i);
}

void    ft_do_cmd(t_data *data, int index)
{
    if (ft_strcmp(data->tab[index].name, "echo") == 0)
        ft_echo(data, index);
    else if (ft_strcmp(data->tab[index].name, "cd") == 0)
        ft_cd(data, index);
    else if (ft_strcmp(data->tab[index].name, "pwd") == 0)
        ft_pwd(data);
    else if (ft_strcmp(data->tab[index].name, "env") == 0)
        ft_env(data);
    else if (ft_strcmp(data->tab[index].name, "unset") == 0)
        ft_unset(data, index);
    else if (ft_strcmp(data->tab[index].name, "exit") == 0)
        quit(0, "");
    else
        ft_other_cmd(data, index);
}

void	ft_get_command(t_data *data, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->cmd[index][i] != '\0' && data->cmd[index][i] == ' ')
		i++;
	while (data->cmd[index][i + j] != '\0' && data->cmd[index][i + j] != ' ')
		j++;
	data->tab[index].name = ft_substr(data->cmd[index], i, j);
	data->tab[index].ac = ft_count_args(data->cmd[index], 0);
	data->tab[index].av = ft_get_args(data, data->cmd[index], 0, data->tab[index].ac + 1);
}


void	ft_parsing(t_data *data, int index)
{
	ft_get_command(data, index);
}
