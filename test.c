#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

#include <stdio.h>

int main()
{

	char *line;
	int i;
	int fd;
	int fd2;
	int fd3;
	int fd4;
	
	fd = open("txt1", O_RDONLY);
	fd2 = open("txt2", O_RDONLY);
	fd3 = open("txt3", O_RDONLY);
	fd4 = open("txt4", O_RDONLY);

	if (fd == -1)
		return (0);
	if (fd2 == -1)
		return (0);
	if (fd3 == -1)
		return (0);


/*** Partie obligatoire ***/	


	/*************    fichier txt standard   ******************/

/*	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("line %d = |%s|\n", i, line);
		free(line);
	}
*/

	/******************   fichier vide    **********************/

/*	i = 1;
	while (i > 0)
	{
		if ((i = get_next_line(fd2, &line)) < 0)
		{
			printf("line %d = |%s|\n", i, line);
			break;
		}
		printf("line %d = |%s|\n", i, line);
		free(line);
	}
*/

	/** fichier avec 1 grande ligne sans retour a la ligne. ****/
	i = 1;
	while (i > 0)
	{
		if ((i = get_next_line(fd3, &line)) < 0)
		{
			printf("line %d = |%s|\n", i, line);
			break;
		}
		printf("line %d = |%s|\n", i, line);
		free(line);
	}


/*** Partie Bonus ***/  //nope

/*
	for (int i = 0; i < 3; i++)
	{
		//printf("%d ||\n", i);
		l = get_next_line(fd, line);
		printf(" || line = %s|\n", line[i]);
		l = get_next_line(fd2, line2);
		printf(" || line2 = %s|\n", line2[i]);
	}
	printf("   || line = %s|\n", line[i - 1]);
*/



/*	i = BUFFER_SIZE;
	printf("BUFFER_SIZE = %d\n", i);
*/
	close(fd);
	close(fd2);
	close(fd3);
	close (fd4);
	printf("boucle infinie :\n");
	while (1)
		;
	return (0);	
}

