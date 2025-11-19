#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int fd = 0;
	fd = open("subject.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}