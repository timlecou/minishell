#include "minishell.h"

void	ft_pwd(t_data *data)
{
	t_env	*tmp;

	tmp = data->env;
	while (tmp->next != NULL)
	{
		if (ft_strncmp(tmp->var, "PWD", 3) == 0)
		{
			ft_putstr(&tmp->var[4]);
			write(1, "\n", 1);
			return ;
		}
		tmp = tmp->next;
	}
}
