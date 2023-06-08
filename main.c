#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open((void *) 0, O_RDONLY);
	if (fd == -1)
		perror("");
	return (0);
}
