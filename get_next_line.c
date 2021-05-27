#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char BUF[10 + 1];
	int bytes;
	int k;
	char *p_n;
	static char *ost;

	k = 1;
	p_n = 0;
	*line  = "\0";

	if (ost)
		*line = ft_strjoin(*line, ost);
	while (k==1 && (bytes = read(fd, BUF, 10)))
	{
		BUF[bytes] = '\0';
		if ((p_n = ft_strchr(BUF,'\n')))
		{
			*p_n = '\0';
			k = 0;
			p_n++;
			ost = ft_strdup(p_n);
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
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return(0);
}