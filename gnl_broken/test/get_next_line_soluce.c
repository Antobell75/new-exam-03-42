/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_soluce.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:37:30 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/14 10:34:12 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
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

size_t	ft_strlen(char *s)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		s++;
		result++;
	}
	return (result);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*tmp;

	size1 = *s1 ? ft_strlen(*s1) : 0;
	tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	if (*s1)
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "";
	char		*result;
	char		*newline;
	int			read_ret;
	size_t		rest;

	result = NULL;
	while (1)
	{
		newline = ft_strchr(buffer, '\n');
		if (newline)
		{
			if (!str_append_mem(&result, buffer, newline - buffer + 1))
				return free(result), (NULL);
			rest = ft_strlen(newline + 1);
			ft_memcpy(buffer, newline + 1, rest + 1);
			return (result);
		}
		else if (!str_append_str(&result, buffer))
			return (free(result), (NULL));
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret <= 0)
		{
			buffer[0] = 0;
			return (result && *result ? result : (free(result), NULL));
		}
		buffer[read_ret] = 0;
	}
}
