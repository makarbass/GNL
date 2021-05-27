#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char BUF[10 + 1];
	int bytes;


	//bytes = read(fd, BUF, 10);
	//printf("READ : %d\n",bytes);
	while ((bytes = read(fd, BUF, 10)))
	{
		BUF[bytes] = '\0';
		*line = ft_strjoin(*line, BUF);
	}
	return (0);
}

int main(void)
{
	int fd;
	char *line;

	fd = open("text.txt",O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return(0);
}