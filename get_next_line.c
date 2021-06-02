#include "get_next_line.h"

char *check_ost(char *ost, char **line)
{
	char *p_n;

	p_n = NULL;
	if (ost)
	{
		if ((p_n = ft_strchr(ost, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(ost);
			ft_strcpy(ost, ++p_n);
		}
		else
		{
			*line = ft_strjoin(*line,ost);
			*ost = '\0';
		}
	}
	return (p_n);
}

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int bytes;
	char *p_n;
	static char *ost;

	*line = "\0";
	p_n = check_ost(ost, line);
	while (!p_n  && (bytes = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bytes] = '\0';
		if ((p_n = ft_strchr(buf,'\n')))
		{
			*p_n = '\0';
			p_n++;
			ost = ft_strdup(p_n);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int main(void)
{
	int fd;
	char *line;

	fd = open("text.txt",O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
		get_next_line(fd, &line);
	printf("%s\n\n", line);
		get_next_line(fd, &line);
	printf("%s\n\n", line);
	return(0);
}