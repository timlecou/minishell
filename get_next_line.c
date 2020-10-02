/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsarafia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:57:13 by tsarafia          #+#    #+#             */
/*   Updated: 2019/12/03 17:13:18 by tsarafia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)s;
	while (n > 0)
	{
		*(ptr++) = 0;
		n--;
	}
}

static int	ft_manage_rest(t_gnl *p, char **line, char **buffer)
{
	char	*rest;
	char	*subline;
	int		empty_rest;

	if ((rest = ft_getrest(*buffer, &empty_rest)) == NULL && empty_rest == 0)
		return (-1);
	if (empty_rest == 1)
	{
		if ((*line = ft_strjoin_gnl(*line, *buffer)) == NULL)
			return (-1);
		ft_bzero(*buffer, BUFFER_SIZE + 1);
		return (1);
	}
	else
	{
		if ((subline = ft_getline(*buffer)) == NULL)
			return (-1);
		if ((*line = ft_strjoin_gnl(*line, subline)) == NULL)
			return (-1);
		p->rest = rest;
		free(subline);
		return (0);
	}
}

static int	ft_rest(t_gnl *p, char **buffer, int fd, char **line)
{
	int ret;

	if (p->rest)
	{
		*buffer = ft_strcpy(*buffer, p->rest);
		free(p->rest);
		p->rest = NULL;
	}
	else
	{
		p->byte_nb = read(fd, *buffer, BUFFER_SIZE);
		if (p->byte_nb <= 0)
			return (p->byte_nb == 0 ? 0 : -1);
	}
	ret = ft_manage_rest(p, line, buffer);
	if (ret == 0)
		return (2);
	if (ret == -1)
		return (-1);
	return (1);
}

static int	ft_read(int fd, t_gnl *p, char **line)
{
	char	*buffer;
	int		ret;

	ret = 0;
	if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (!(*line = malloc(sizeof(char) * 1)))
	{
		free(buffer);
		return (-1);
	}
	*line[0] = '\0';
	while (ret != 2)
	{
		ret = ft_rest(p, &buffer, fd, line);
		if (ret <= 0)
		{
			free(buffer);
			return (ret);
		}
	}
	free(buffer);
	return (p->byte_nb > 0 || p->rest ? 1 : 0);
}

int			get_next_line(int fd, char **line)
{
	static t_gnl	p;
	int				ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL || read(fd, 0, 0) < 0)
		return (-1);
	ret = ft_read(fd, &p, line);
	return (ret);
}
