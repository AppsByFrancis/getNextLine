#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main ()
{
	int fd;
	char buffer[1024];
	char chars_read;	

	fd = open("./text.txt", O_RDONLY);

	while((chars_read = read(fd, buffer, 5)))
	{
		buffer[chars_read] = '\0';
		printf("%s", buffer);
	}

	return 0;
}
