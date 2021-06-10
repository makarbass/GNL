#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return(0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_strendl(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return(1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	int len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = malloc(sizeof(char) * len)))
		return(NULL);
	i = 0;
	str[len - 1] = '\0';
	if (s1)
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
	j = 0;
	if (s2)
		while (s2[j] != '\0')
			str[i++] = s2[j++];
	free(s1);
	return (str);
}

char    *ft_getline(char *mem)
{
        char *tmp;
        int     i;

        i = 0;
        while (mem && mem[i] != '\0' && mem[i] != '\n')
        	i++;
        if (!(tmp = malloc(sizeof(char) * (i + 1))))
        	return(NULL);
        i = 0;
        while (mem && mem[i] != '\0' && mem[i] != '\n')
        {
                tmp[i] = mem[i];
                i++;
        }
        tmp[i] = '\0';
        return (tmp);
}

char	*ft_clearmem(char *mem)
{
	char	*tmp;
	int len;
	int i;
	int j;

	i = 0;
	if (!mem)
		return(NULL);
	while (mem[i] != '\0' && mem[i] != '\n')
		i++;
	if (mem[i] == '\0')
	{
		free(mem);
		return (NULL);
	}
	len = ft_strlen(mem) - i;
	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i++;
	j = 0;
	while (mem[i] != '\0')
		tmp[j++] = mem[i++];
	tmp[j] = '\0';
	free(mem);
	return	(tmp);
}