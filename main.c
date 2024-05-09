#include "get_next_line.h"


int	main()
{
	int fd = open("lines_around_10.txt", O_RDONLY);
	printf("main: \n");
	printf("%s", get_next_line(fd));
}