#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int fd = open("lines_around_10.txt", O_RDONLY);
	char *p = get_next_line(fd);
	while (p != NULL)
	{
		printf("p:%s", p);
		p = get_next_line(fd);
	}
	
}