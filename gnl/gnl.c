char *get_next_line(int fd)
{
	static char *buffer[BUFFER_SIZE]
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
		buffer = read(fd, buffer, BUFFER_SIZE);
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