/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:28:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/11 13:52:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** 
*/

int		get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				end_of_line;
	int 			len;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, buf, 0) == -1))
		return(-1);
	len = 0;
	*line = ft_strjoin_max_free_s1(NULL, buf, 0);
	while ((end_of_line = ft_strchr_len(buf, '\n')) < 0)
	{
		if ((copy_buf_in_line(line, buf, end_of_line, len) == -1)
		|| ((len = read(fd, buf, BUFFER_SIZE)) <= 0))
			return (stop_read(line, buf, end_of_line, len));
	}
	return (stop_read(line, buf, end_of_line, len));
}

/*
**
*/

int		stop_read(char **line, char *buf, int end_of_line, int len)
{
	if  (len == -1)
	{
		if (*line)
		{
			free (*line);
			*line = NULL;
		}
		return (-1);
	}
	if ((copy_buf_in_line(line, buf, end_of_line, len)) != 0)
		return (stop_read(line, buf, end_of_line, -1));
	return(0);
}

/*
**
*/

int		copy_buf_in_line(char **line, char *buf, int end_of_line, int len)
{
	/*if (ft_strlen(buf) != BUFFER_SIZE)
		*line = ft_strjoin_max_free_s1(*line, buf, len);
	else if (end_of_line == -1 && len)
		*line = ft_strjoin_max_free_s1(*line, buf, len);
*/

	if (end_of_line == -1 && len == 0)
		len = ft_strlen(buf);
	else
		len = end_of_line;
	if (buf[0] != '\0')
	*line = ft_strjoin_max_free_s1(*line, buf, len);
	buf = ft_strncpy(buf, buf + end_of_line + 1, BUFFER_SIZE);
	if (*line == NULL)
		return (-1);
	return (0);
}