#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

char	*ft_strdup(const char *s1);
int	ft_strlen(const char *str);
void *ft_memcpy (void *dest, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int ch);
void	*ft_memccpy (void *destination, const void *source, int c, size_t n);

#endif