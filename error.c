
#include "minishell.h"

void	quit(int state, char *str)
{
    ft_putstr(str);
	exit(state);
}
