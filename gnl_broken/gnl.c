/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:49:49 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/18 15:33:45 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 5

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
	size_t	ret;
	ret = 0;
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*tmp;

	size1 = *s1 ? ft_strlen(*s1) : 0;
	tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
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
	char		*res;
	char		*new;
	int			read_ret;
	size_t	len;

	res = NULL;
	while (1)
	{
		new = ft_strchr(buffer, '\n');
		if (new)
		{
			if (!str_append_mem(&res, buffer, new - buffer +1));
				return (free (res), NULL);
			new++;
			len = ft_strlen(new) + 1;
			ft_memcpy(buffer, new, len);
		}
		else if (!str_append_str(&res, buffer))
			return free (res),(NULL);

		read_ret = read(fd, buffer, BUFFER_SIZE);
		if(read_ret <= 0)
		{
			buffer[0] = 0;
			return res && *res ? res : (free (res), NULL);
		}
		buffer[read_ret] = 0;
	}
}
