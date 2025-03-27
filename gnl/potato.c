# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);

#endif

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int position;
	static int size_read;
	char line[7000];

	int i = 0;
	while(1)
	{
		if (position >= size_read)
		{
			size_read = buffer[BUFFER_SIZE];
			position = 0;
		}

	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
