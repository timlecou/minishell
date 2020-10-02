
#include "minishell.h"

void    ft_echo(t_data *data, int index)
{
    int i;

    i = 1;
    if (ft_strcmp(data->tab[index].av[1], "-n") == 0)
    {
        data->tab[index].is_op = 1;
        i++;
    }
    while (i < data->tab[index].ac)
    {
        ft_putstr(data->tab[index].av[i]);
        if (i < data->tab[index].ac - 1)
            write(1, " ", 1);
        i++;
    }
    if (data->tab[index].is_op == 0)
        write(1, "\n", 1);
}
