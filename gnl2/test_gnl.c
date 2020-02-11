/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:15:09 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/11 16:03:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int 	i;
	int		fd;
	int		fd2;
	int		fd3;
	int		fd4;

	char	*line; //= NULL;

	fd = open("txt1", O_RDONLY);
	fd2 = open("txt2", O_RDONLY);
	fd3 = open("txt3", O_RDONLY);
	fd4 = open("txt4", O_RDONLY);
	
/*	printf("FD 0 = %d\n", get_next_line(0, &line));
	printf("NULL = %d\n", get_next_line(fd, NULL));
	printf("LINE NULL = %d\n", get_next_line(fd, &line)); // verifier line null avec fd)
	line = "pouet";
	printf("FD inexistant = %d\n", get_next_line(45, &line));
*/

	/* ****************** FD 1 txt Normal *********************** */

	i = 0;

	while ((i = get_next_line(fd2, &line)) >= 0)
	{
		printf("line %d = |%s|\n", i, line);
		free(line);
	}
	
	
	
	close (fd);
	close (fd2);
	close (fd3);
	close (fd4);
	return (0);
}