/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:28:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/09 18:53:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** 
*/

int		get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE];
	int				end_of_line;
	size_t 			len;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, buf, 0) == -1))
		return(-1);
	end_of_line = ft_strchr_len(buf, '\n');
	while (end_of_line == 0 && buf[0] != '\n')
	{
		if ((len = read(fd, buf, BUFFER_SIZE)) < 1)
			return(stop_read());
		if ((end_of_line = ft_strchr_len(buf, '\n')) != 0)
		{
			*line = ft_strjoin_max_free_s1(*line, buf, end_of_line);
			ft_strlcpy(buf, buf + end_of_line, BUFFER_SIZE);
			stop_read();
		}	
		else
		{
			*line = ft_strjoin_max_free_s1(*line, buf, len);
		}	
	}
	if (buf[0] == '\n')
		*line = ft_strjoin_max_free_s1(*line, buf, 1);
	return (1);
}

/*
**
*/

int		stop_read(void)
{
	return(0);
}