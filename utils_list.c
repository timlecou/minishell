#include "minishell.h"

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*begin;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst && *lst && new)
	{
		begin = *lst;
		while (begin->next)
			begin = begin->next;
		begin->next = new;
	}
}

t_env	*ft_lstnew(char *content)
{
	t_env	*elem;

	if (!(elem = malloc(sizeof(t_env))))
		return ((t_env*)NULL);
	if (ft_strncmp(content, "SHLVL", 5) == 0)
	    elem->var = ft_inc_shlvl(content);
	else
	    elem->var = ft_strdup(content);
	elem->next = NULL;
	return (elem);
}

t_env	*ft_fill_env_list(char **envp)
{
	t_env	*env;
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_lstadd_back(&env, ft_lstnew(envp[i]));
		i++;
	}
	return (env);
}
