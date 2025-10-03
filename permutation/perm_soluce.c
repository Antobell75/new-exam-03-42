/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:19:50 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/08 13:48:48 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



void	swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b =tmp;
}

void	sort(char *str)
{
	int	i;
	int	j;

	i = 0;
	while(str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}

}

void perm(char *src, char *buf, int *used, int pos, int n)
{
	if (n == pos)
	{
		buf[n] = '\0';
		printf("%s\n", buf);
		return;
	}
	int i = 0;
	while(i < n)
	{
		if (!used[i])
		{
			used[i] = 1;
			buf[pos] = src[i];
			perm(src, buf, used, pos + 1, n);
			used[i] = 0;
		}
		i++;
	}

}


int	 main(int ac, char **av)
{
	if (ac != 2 || *av[1] == '\0')
		return (1);
	char	*buf;
	int	*used;
	int	n;

	n = strlen(av[1]);
	buf = malloc(n + 1);
	used = malloc(sizeof(int) * n);
	if (!buf || !used)
		return (free(buf), free(used), (1));
	int	k = 0;
	while(k < n)
	{
		used[k] = 0;
		k++;
	}
	sort(av[1]);
	perm(av[1], buf, used, 0, n);
	free(buf);
	free(used);
	return (0);
}
