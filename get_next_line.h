/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmajer <fmajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:45:12 by fmajer            #+#    #+#             */
/*   Updated: 2024/10/12 00:01:06 by fmajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *string, int searchedChar);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t object_count, size_t object_size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
