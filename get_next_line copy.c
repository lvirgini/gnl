/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:30:25 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/11 09:50:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Verifie si GNL n'a jamais ete appelee : malloc de *next;
** sinon verifie s'il y a un (\n) dans le *next.
*/

char	*ft_if_wait(char *wait, int *end_of_line)
{
	if (!wait)
	{
		if (!(wait = malloc(sizeof((*wait) * BUFFER_SIZE))))
			return (NULL);
		*end_of_line = 0;
	}
	else
		*end_of_line = ft_strchr_i(wait, '\n');
	return (wait);
}

/*
** free de la partie de next qui a ete envoyee dans *line.
*/

char	*ft_next_wait(char *before, int end_of_line)
{
	char *tmp;

	tmp = ft_strdup(before + end_of_line + 1);
	free(before);
	return (tmp);
}

/*
** si read renvoie 0 ou -1 : soit erreur, soit EOF.
** free de *next et ecriture de la derniere ligne dans **line.
*/

int		ft_stop_read(int len, char *wait, char **line, char *buf)
{;
	if (len != -1)
		*line = ft_strjoin(buf);
	if (len == -1)
	{
		if (*line)
			free(*line)
		return (-1);
	}
		
	return (0);
}

/*
** tant que '\n' n a pas ete trouve, on lit.
*/

int		get_next_line(int fd, char **line)
{
	static char		*wait = NULL;
	static char		buf[BUFFER_SIZE + 1];
	int				end_of_line;
	int				len;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || (read(fd, buf, 0) == -1))
		return (-1);
	if (!(*line = ft_if_wait(wait, &end_of_line)))
		return (ft_stop_read(-1, wait, line, buf));
	while (end_of_line == 0 && buf[0] != '\n')
	{
		if ((len = read(fd, buf, BUFFER_SIZE)) <= 0)
			return (ft_stop_read(len, wait, line, buf));
		if (!(*line = ft_strjoin_s1_free(*line, buf)))
			return (ft_stop_read(-1, wait, line, buf));
		end_of_line = ft_strchr_i(buf, '\n');
	}
	buf[end_of_line] = '\0';
	*line = ft_strdup(wait);
	buf = ft_next_wait(buf, end_of_line);
	return (1);
}
