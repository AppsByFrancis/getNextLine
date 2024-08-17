#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

typedef struct s_list
{
	char *buffer;
	struct s_list *next_node;
}	t_list;

t_list *get_last_node(t_list *list)
{
	if(list == NULL)
		return(NULL);
	while(list->next_node)
		list = list->next_node;
	return list;
}

void append_to_list(t_list **list, char *buff)
{
	t_list *last_node;
	t_list *new_node;

	
	new_node = malloc(sizeof(t_list));
	if(new_node == NULL)
		return;
	last_node = get_last_node(*list);
	if(last_node == NULL)
		*list = new_node;
	else
		last_node->next_node = new_node;
	new_node->buffer = buff;
	new_node->next_node = NULL;
}

int get_str_len(t_list *list)
{
	int i;
	int temp;

	i = 0;
	while(list)
	{
		temp = 0;
		while(list->buffer[temp])
			temp++;
		i += temp;
		list = list->next_node;
	}
	return i;
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return i;
}

void copy_to_string(char *str, char *buffer, int k)
{
	int i;

	i = 0;
	while(buffer[i])
		str[k++] = buffer[i++];
}

int new_line(t_list *list)
{
	int i;

	i = 0;
	if (NULL == list)
		return (0);
	while(list)
	{
		while(list->buffer[i])
		{
			if(list->buffer[i] == '\n')
				return 1;
			i++;
		}
		list = list->next_node;
	}

	return(0);
}

char *get_line(t_list *list)
{
	char *str;
	int i;

	i = 0;
	int len = get_str_len(list);

	str = malloc(len + 1);
	if(str == NULL)
		return NULL;
	
	if (list == NULL)
		return (NULL);
	while(!new_line(list))
	{	
		copy_to_string(str, list->buffer, i);
		i += ft_strlen(list->buffer);
		// printf("%d", ft_strlen(list->buffer));
		list = list->next_node;
	}
	str[len] ='\0';
	return str;
}

void free_list(t_list *list)
{
	t_list *temp;
	while(list)
	{
		temp = list;
		list = list->next_node;
		free(temp->buffer);
		free(temp);
	}
	list = NULL;
}

char *get_next_line(int fd)
{
	static t_list *string_list;
	char *arr;
	char *buffer;
	size_t chars_read;

	arr = "NULL";
	while((buffer = malloc(BUFFER_SIZE + 1)) != NULL && (chars_read = read(fd, buffer, 5)))
	{
		buffer[chars_read] = '\0';
		append_to_list(&string_list, buffer);
	}
	
	if(buffer == NULL)
	{
		return NULL;
	}

	if(chars_read <= 0)
	{
		if (chars_read == -1) {
            perror("Error reading file");
        }
		free(buffer);
	}

	arr = get_line(string_list);
	free_list(string_list);

	return(arr);

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
