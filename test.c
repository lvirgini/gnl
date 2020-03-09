#include "get_next_line_bonus.h"
#include <libc.h>

int main(int ac, char **av)
{
	char *line = NULL;
	int i = 1;
	int j = 1;

	(void)ac;
	int fd1 = open(av[1], O_RDONLY);
	int fd2 = open(av[2], O_RDONLY);

	while (i != 0 && j != 0)
	{
		if ((i = get_next_line(fd1, &line)) == 1)
		{
			printf("fd1 ret= %i => |%s|\n", i, line);
			free(line);
		}
		if ((j = get_next_line(fd2, &line)) == 1)
		{
			printf("fd2 ret= %i => |%s|\n", j, line);
			free(line);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}