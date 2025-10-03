/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fiter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:21:47 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/18 16:13:57 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

int	main(int ac, char **av)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytesread;
	size_t	totalread;
	char	*tmp;
	char	*res;

	res = NULL;
	totalread = 0;
	while ((bytesread = read(0, buffer, BUFFER_SIZE)))
	{
		tmp = realloc(res, totalread + bytesread + 1);
		if (!tmp)
			return (free(res), perror("Error: "), 1);
		res = tmp;
		memcpy(res + totalread, buffer, bytesread);
		totalread += bytesread;
	}
	if (bytesread < 0)
		return (free(res), perror("Error: "), 1);
	tmp = realloc(res, totalread + 1);
	if (!tmp)
		return (free(res), perror("Error: "), 1);
	res = tmp;
	res[totalread] = '\0';
}
