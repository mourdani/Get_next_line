#include "get_next_line.h"


int main()
{
	char *line;
	int fd;
 	int gnl;

 	fd = open("file.txt", O_RDONLY);
 	while ((gnl = get_next_line(fd, &line)) > 0)
 {
 	printf("%s\n", line);
 	free(line);
 }
 	printf("%s", line);
 	free(line);
 	return 0;
 }
