#include "minishell.h"

void	ft_free_splitted_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
	    if (arr[i])
		    free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_del_elem(t_env *elem)
{
	free(elem->var);
	free(elem);
}

void	ft_lstclear(t_env **lst, void (*del)(t_env *))
{
	t_env	*tmp;

	if (lst && *lst && del)
	{
		tmp = (*lst);
		while (tmp)
		{
			(*lst) = (*lst)->next;
			del(tmp);
			tmp = (*lst);
		}
	}
	*lst = NULL;
}

void	ft_free_data_struct(t_data *data)
{
    int i;

    i = 0;
    ft_free_splitted_array(data->cmd);
    while (i < data->nb_cmd)
    {
        free(data->tab[i].name);
        ft_free_splitted_array(data->tab[i].av);
        i++;
    }
    free(data->tab);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len;

	len = ft_strlen(dst) + ft_strlen(src);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (*dst)
		dst++;
	i = 0;
	while ((i < size - (len - ft_strlen(src)) - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}
