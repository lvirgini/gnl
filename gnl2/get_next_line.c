/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:28:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/12 18:15:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**  GNL : retourne -1 si probleme :
**				- fd inexistant ou < 0;
**				- BUFFER_SIZE non conforme ( < 1);
**				- line a NULL;
**	- tant que (\n) n'est pas trouve dans le buffer, on lit le fd.
**	tout en copiant le buffer dans *line.
**	- on arrete de (read) des (\n).
**	- retourne 1 pour chaque ligne copiee.
**	- retourne 0 des qu'il n'y a plus de ligne a renvoyer et que le fd a ete
**	lu entierement.
*/

int		get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				end_of_line;
	int				len;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, buf, 0) == -1))
		return (-1);
	len = 0;
	*line = ft_strjoin_max_free_s1(NULL, buf, 0);
	while ((end_of_line = ft_strchr_len(buf, '\n')) < 0)
	{
		if ((copy_buf_in_line(line, buf, end_of_line, len) != 1)
		|| ((len = read(fd, buf, BUFFER_SIZE)) < BUFFER_SIZE))
			return (stop_read(line, buf, end_of_line, len));
	}
	return (copy_buf_in_line(line, buf, end_of_line, len));
}

/*
** Copie tout ou une partie de buf dans line.
*/

int		copy_buf_in_line(char **line, char *buf, int end_of_line, int len)
{
	if (end_of_line == -1)
	{
		if (len <= 0)
			len = ft_strlen(buf);
	}
	else
		len = end_of_line;
	if (buf[0] == '\n')
		len = 0;
	*line = ft_strjoin_max_free_s1(*line, buf, len);
	buf = ft_strncpy(buf, buf + len + 1, BUFFER_SIZE);
	if (*line == NULL)
		return (-1);
	return (1);
}

/*
** quand la fonction (read) a entierement lu le fd, ou si pb (-1)
*/

int		stop_read(char **line, char *buf, int end_of_line, int len)
{
	if (len == -1)
	{
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
		return (-1);
	}
	else
	{
		if ((end_of_line = ft_strchr_len(buf, '\n')) >= 0 || ft_strlen(buf) > 0)
		{
			copy_buf_in_line(line, buf, end_of_line, len);
			return (1);
		}
		free(*line);
		*line = NULL;
		return (0);
	}
}
