#include "get_next_line.h"

int main()
{
	char *line;
	int fd;

	fd = open("poem.txt", O_RDONLY);
	printf("gnl : %d\n", get_next_line(fd, &line));
	printf("line : %s\n", line);
	return 0;
}

int	join_move(char *store, char **line, int i)
{
	int		len;

	*line = ft_substr(store, 0, i);
	++i;
	len = ft_strlen(store + i) + 1;
	ft_memmove(store, store + i, len);
	return (1);
}

int get_next_line(int fd, char **line)
{
	static char *store;
	char buff[BUFF_SIZE + 1];
	int ret;
	int i;
	
	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (store && (i = ft_strchr(store, '\n')))
		return (join_move(store, line, i));
	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[BUFF_SIZE] = '\0';
		store = join_free(store, buff);
		if ((i = ft_strchr(store, '\n')) != 0)
		{
			printf("store before substr : %s\n\n", store);
			join_move(store, line, i);
			printf("store after  substr : %s\n\n", store);
			printf("***line : %s\n", *line);
		}
	}		
	return (-1);
}
