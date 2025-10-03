/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_soluc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:22:17 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/18 15:48:49 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 8

int	get_identique(char *str, char *replace, size_t s_replace, size_t len)
{
	if (len < s_replace)
		return (0);
	for (size_t i = 0; i < s_replace; i++)
		if (str[i] != replace[i])
			return (0);
	return (1);
}

void	transform_world(char *str, char *replace, size_t total_len)
{
	size_t	i;
	size_t	s_replace;

	i = 0;
	s_replace = strlen(replace);
	while (i < total_len)
	{
		if (get_identique(str + i, replace, s_replace, total_len - i))
		{
			for (size_t j = 0; j < s_replace; j++)
				str[i + j] = '*';
			i += s_replace;
		}
		else
			i++;
	}
}


int	main(int argc, char **argv)
{
	char	buffer[BUFFER_SIZE];
	char	*result;
	char	*temp;
	ssize_t	bytes_read;
	size_t	total_bytes;

	result = NULL;
	total_bytes = 0;
	if (argc != 2 || strlen(argv[1]) == 0)
		return (1);
	while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		temp = realloc(result, total_bytes + (size_t)bytes_read + 1);
		if (!temp)
			return (free(result), 1);
		result = temp;
		memcpy(result + total_bytes, buffer, (size_t)bytes_read);
		total_bytes += (size_t)bytes_read;
	}
	if (bytes_read < 0)
		return (free(result), 1);
	temp = realloc(result, total_bytes + 1);
	if (!temp)
		return (free(result), 1);
	result = temp;
	result[total_bytes] = '\0';
	transform_world(result, argv[1], total_bytes);
	printf("%s", result);
	free(result);
	return (0);
}
