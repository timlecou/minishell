

#include "minishell.h"

void    ft_manage_line(char *line)
{
    if (ft_strncmp(line, "exit", 4) == 0)
        exit(EXIT_SUCCESS);
}

void    ft_minishell(void)
{
    char    *line;

    line = NULL;
    while (1)
    {
        write(1, "$>", 2);
        get_next_line(0, &line);
		ft_manage_line(line);
    }
}

int     main(void)
{
    ft_minishell();
    return (0);
}

