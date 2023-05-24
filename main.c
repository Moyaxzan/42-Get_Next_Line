#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int	fd = 0;
	char	*buffer;
	int	cpt = 0;

	//fd = open("file.txt", O_RDONLY);
	do
	{
		buffer =  get_next_line(fd);
		++cpt;
		printf("%d gnl = %s\n", cpt, buffer);
		free(buffer);
	} while (buffer);
	return (0);
}
