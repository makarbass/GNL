#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char BUF[10 + 1];
	int bytes;
	int k;
	char *p_n;

	k = 1;
	p_n = 0;
	*line  = "\0";
	//bytes = read(fd, BUF, 10);
	//printf("READ : %d\n",bytes);
	while (k==1 && (bytes = read(fd, BUF, 10)))
	{
		BUF[bytes] = '\0';
		if ((p_n = ft_strchr(BUF,'\n')))
		{
			*p_n = '\0';
			k = 0;
		}
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
	printf("\n");
	get_next_line(fd, &line);
	printf("%s\n", line);
	return(0);
}