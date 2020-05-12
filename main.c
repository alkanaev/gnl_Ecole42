

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"




int	main()
{
	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
//	fd = 1;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
//		line = NULL;
		if (line)
			free(line);
	}
	printf("%s\n", line);
	if (line)
		free(line);
	while(1);
	return (0);
}
