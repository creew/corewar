#include "awm.h"

int main(int main, char **argv)
{
	int fd;
	char *line;
	int i;

	fd = open(argv[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s    %d \n", line, i);
	}
	printf("%d", i);
}