
#include"get_next_line.h"

char	*get_next_line(int fd)
{
	int i = 0;
	int rd = 0;
	char character;
	char *buffer = NULL;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(1000);
	while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1) > 0))
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if ((rd == -1 || !rd) || i == 0)
	{
		free(buffer);
		return (NULL);
	}
	return(buffer);
}

/* int	main(void)
{
	int		i;
	char	*result;
	int		fd;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 2)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free(result);
		i++;
	}
	close(fd);
} */
