/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmajer <fmajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:15:17 by fmajer            #+#    #+#             */
/*   Updated: 2024/10/06 16:20:07 by fmajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int x)
{
	char	*last_c;

	last_c = NULL;
	while (*str)
	{
		if (*str == (char)x)
			last_c = (char *)str;
		str++;
	}
	if (*str == '\0' && x == 0)
		last_c = (char *)str;
	return (last_c);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t object_count, size_t object_size)
{
	void	*ptr;
	if(object_count <= 0 || object_size <= 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if ((object_count * object_size) / object_size != object_count)
		return (NULL);
	ptr = malloc(object_count * object_size);
    if (!ptr)
        return (NULL);
	ft_bzero(ptr, object_count * object_size);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return ((size_t)i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char *ft_strjoin (char const *s1, char const *s2)
{
    size_t len1;
    size_t len2;
    char *ptr;

    if(!s1 || !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    ptr = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!ptr)
        return (NULL);
    ft_memcpy(ptr, s1, len1);
    ft_memcpy(ptr + len1, s2, len2 + 1); // to null terminate it
    return (ptr);
}

