#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft.h"

#define BUFFER_SIZE 5

char *ft_free_and_copy(char *buffer, char *bufferRead)
{
	char *temp;

	temp = ft_strjoin(buffer, bufferRead);

	free(buffer);
	return(temp);
}

char *read_file(int fd, char *buffer)
{
	char *buffRead;
	int byte_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if(!buffer)
		return (NULL);

	buffRead = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffRead)
		return (NULL);

	byte_read = 1;

	while(byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if(byte_read == -1)
		{
			free(buffRead);
			return (NULL);
		}
		buffRead[byte_read] = 0;

		buffer = ft_free_and_copy(buffer, buffRead);

		if (ft_strchr(buffer, '\n'))
			break;
	}

	free(buffRead);
	return (buffer);


}

char *get_next_line(int fd)
{
	static char *buffer;
	char *returnLine;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);

}

int	main()
{
	int fd;
	char  *str;

	fd = open("./text.txt", O_RDONLY);
	str = get_next_line(fd);
	str = get_next_line(fd);

	if(str)
	{
		printf("%s", str);	
		free(str);
	}

	// printf("%s", str);
}
