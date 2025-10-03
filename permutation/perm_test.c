/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perm_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:14:23 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/17 11:35:53 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	res(char *arg, char *buffer, int pos, int *used, int len)
{
	if (pos == len)
	{
		buffer[len] = 0;
		printf('%s\n', buffer);
		return ;
	}
	for (int i = 0; i < len; i++)
	{
		if (!used)
		{
			used[i] = 1;
			buffer[pos] = arg[i];
			res(arg, buffer, pos + 1, used, len);
			used[i] = 0;
		}
	}
}
int	main(int ac, char **arg)
{
	int		*used;
	size_t	len;
	char	*buffer;

	len = strlen(arg[1]);
	buffer = malloc(len + 1);
	used = calloc(len, sizeof(char));
	srot(arg[1]);
	res(arg[1], buffer, 0, used, len);
}
