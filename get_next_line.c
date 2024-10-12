/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmajer <fmajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:15:17 by fmajer            #+#    #+#             */
/*   Updated: 2024/10/12 00:01:25 by fmajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *buffer, char *buffer_read)
{
	char	*temp;

	temp = ft_strjoin(buffer, buffer_read);
	free(buffer);
	return (temp);
}

char	*read_file(int fd, char *buffer, char *buff_read)
{
	int		bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	while (1)
	{
		bytes_read = read(fd, buff_read, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff_read);
			free(buffer);
			return (NULL);
		}
		buff_read[bytes_read] = 0;
		buffer = ft_join(buffer, buff_read);
		if (!buffer)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buff_read, '\n') || !bytes_read)
			break ;
	}
	free(buff_read);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*return_line;
	char		*buff_read;

	if (fd < 0 || !BUFFER_SIZE)
	{
		free(buffer);
		return (NULL);
	}
	buff_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = read_file(fd, buffer, buff_read);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	return_line = ft_get_line(buffer);
	buffer = ft_next(buffer);
	return (return_line);
}
