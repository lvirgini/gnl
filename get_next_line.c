/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:30:25 by lvirgini          #+#    #+#             */
/*   Updated: 2020/01/29 17:55:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Verifie si GNL n'a jamais ete appelee : malloc de *next;
** sinon verifie s'il y a un (\n) dans le *next.
*/

char	*ft_if_wait(char *wait, int *end)
{
	if (!wait)
	{
		if (!(wait = malloc(sizeof((*wait) * BUFFER_SIZE))))
			return (NULL);
		*end = 0;
	}
	else
		*end = ft_strchr_i(wait, '\n');
	return (wait);
}

/*
** free de la partie de next qui a ete envoyee dans *line.
*/

char	*ft_next_wait(char *before, int end)
{
	char *tmp;

	tmp = ft_strdup(&before[end + 1]);
	free(before);
	return (tmp);
}

/*
** si read renvoie 0 ou -1 : soit erreur, soit EOF.
** free de *next et ecriture de la derniere ligne dans **line.
*/

int		ft_stop_read(int len, char *wait, char **line, char *buf)
{
	free(buf);
	if (wait && len != -1)
	{
		*line = ft_strdup(wait);
		wait[0] = '\0';
	}
	if (len == -1)
		return (-1);
	free(wait);
	return (0);
}

/*
** tant que '\n' n a pas ete trouve, on lit.
*/

int		get_next_line(int fd, char **line)
{
	static char		*wait;
	char			*buf;
	int				end;
	int				len;

	if (BUFFER_SIZE <= 0 || line == NULL || fd < 0
	|| (!(wait = ft_if_wait(wait, &end)))
	|| (!(buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1)))))
		return (-1);
	if (*line)
		free(*line);
	while (end == 0 && wait[0] != '\n')
	{
		if ((len = read(fd, buf, BUFFER_SIZE)) <= 0)
			return (ft_stop_read(len, wait, line, buf));
		buf[len] = '\0';
		if (!(wait = ft_strjoin_s1_free(wait, buf)))
			return (ft_stop_read(-1, wait, line, buf));
		end = ft_strchr_i(wait, '\n');
	}
	wait[end] = '\0';
	*line = ft_strdup(wait);
	wait = ft_next_wait(wait, end);
	free(buf);
	return (1);
}
