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
	char *result;
	int i = 0;

	if (!*src)
		return (NULL);
	result = malloc(ft_strlen(src) + 1 * sizeof(char));
	while(src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int position;
	static int bytes_read;
	char line[70000];
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while(1)
	{
	if(position >= bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		position = 0;
		if (bytes_read == 0)
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