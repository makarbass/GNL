#include "get_next_line.h"

int     get_next_line(int fd, char **line)
{
        char            *buf;
        static char     *mem;
        int             get;

        if (fd < 0 || line == NULL || BUFFER_SIZE <= 0) 
                return(-1);
        if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
                return(-1);
        get = 1;
        while ((get = read(fd, buf, BUFFER_SIZE)) > 0)
        {
                buf[get] = '\0';
                mem = ft_strjoin(mem, buf);
                if (ft_strendl(mem))
                        break;
        }
        free(buf);
        if (get < 0)
                return (-1);
        *line = ft_getline(mem);
        mem = ft_clearmem(mem);
        if (get == 0 && !mem)
                return(0);
        return (1);
}  
