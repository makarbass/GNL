#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*mem;
	int			get;

	if (fd < 0 || line == NULL || BUFFER_SIZE <=0)
		return (-1);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	get = read(fd, buf, BUFFER_SIZE);
	while (get > 0)
	{
		buf[get] = '\0';
		mem = ft_strjoin(mem, buf);
		if (ft_strendl(mem))
			break ;
		get = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (get < 0)
		return (-1);
	*line = ft_getline(mem);
	mem = ft_clearmem(mem);
	if (get == 0 && !mem)
		return (0);
	return (1);
}
