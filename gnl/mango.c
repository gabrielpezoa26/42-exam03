#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);

#endif 



int ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}
char	*ft_strdup(char *src)
{
	char *dest;
	int i = 0;

	if (!*src)
		return (NULL);
	dest = malloc(ft_strlen(src) + 1 * sizeof(char));
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int position;
	static int mango;
	char line[7000];
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while(1)
	{
	if(position >= mango)
	{
		mango = read(fd, buffer, BUFFER_SIZE);
		position = 0;
		if (mango == 0)
			break ;
	}
	line[i++] = buffer[position++];
	if (buffer[position] == '\n')
		break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}




int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}