#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int get_next_line(int fd, char **line);
char    *ft_getline(char *mem);
int		ft_strlen(char *str);
int 	ft_strendl(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_clearmem(char *mem);

#endif