/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:19:09 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/15 16:01:12 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g = 0;
void	solve(char **arr, char **result, int pos, int sum, int add)
{
	if (!arr[0])
	{
		if (add == sum)
		{
			g = 1;
			for (int i = 0; i < pos; i++)
			{
				if (i)
					printf(" ");
				printf("%s", result[i]);
			}
			printf("\n");
		}
		return ;
	}
	solve(arr + 1, result, pos, sum, add);
	result[pos] = arr[0];
	solve(arr + 1, result, pos + 1, sum, add + atoi(arr[0]));
}

int	main(int ac, char **av)
{
	int		sum;
	int		len;
	char	**result;

	if (ac < 3)
		return (0);
	for (int i = 1; av[i]; i++)
		if ((av[i][0]) && atoi(av[i]) == 0 && av[i][0] != '0')
			return (1);
	sum = atoi(av[1]);
	len = ac - 2;
	result = calloc(len, sizeof(char *));
	if (!result)
		return (1);
	solve(av + 2, result, 0, sum, 0);
	if(!g)
		printf("\n");
	free(result);
	return (0);
}
