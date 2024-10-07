#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int ft_strchr(char *str, char chr)
{
	while(*str)
	{
		if(*str == chr)
			return(1);
		str++;
	}
	return(0);
}

void read_file()
{
	int fd;
	char buffer[1024];
	int chars_read;
	int i;

	i = 0;
	fd = open("./text.txt", O_RDONLY);

	while((chars_read = read(fd, buffer, 5)))
	{
		buffer[chars_read] = '\0';
		if(ft_strchr(buffer, '\n'))
		{
			printf("%s", "found");
			return;
		}
	}
	printf("%s", "not found");
}

char *get_next_line()
{
	
}

int main ()
{
	// char *str = "Hello World";

	// printf("%d", ft_strchr(str, 'N'));
	read_file();
	return 0;
}
