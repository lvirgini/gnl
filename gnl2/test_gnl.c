/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:15:09 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/12 19:17:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
/*	char *buf;
	int	ret;
	
	for (int i = 3; i < 1000; i++)
	{
		ret = get_next_line(i, &buf);
		if (ret != -1)
			printf("%d  %d\n",i, ret);
	}
*/
	int 	i;
	int		fd;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;

	char	*line; //= NULL;

	fd = open("TEST/txt1", O_RDONLY);
	fd2 = open("TEST/txt2", O_RDONLY);
	fd3 = open("TEST/txt3", O_RDONLY);
	fd4 = open("TEST/txt4", O_RDONLY);
	fd5 = open("gnl3_2.txt", O_RDONLY);

//	printf("FD 0 = %d\n", get_next_line(0, &line));
//	printf("NULL = %d\n", get_next_line(fd, NULL));
//	printf("LINE NULL = %d\n", get_next_line(fd, &line)); // verifier line null avec fd)
//	line = "pouet";
//	printf("FD inexistant = %d\n", get_next_line(45, &line));


	/* ****************** FD 1 txt Normal *********************** */

	i = 0;

	while ((i = get_next_line(fd4, &line)) > 0)
	{
		printf("line %d = |%s|\n", i, line);
		free(line);
	}
	printf("line %d = |%s|\n", i, line);
	free(line);
	
	close (fd);
	close (fd2);
	close (fd3);
	close (fd4);
	
	return (0);
}