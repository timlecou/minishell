#include "minishell.h"

void	ft_env(t_data *data)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp != NULL)
	{
		ft_putstr(tmp->var);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}
