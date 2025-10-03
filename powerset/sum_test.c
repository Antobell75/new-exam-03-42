/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 08:57:07 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/17 11:11:11 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	solve(char **arg, char **res, int pos, int sum, int add)
{
	if (!arg[0])
	{
		if (add == sum)
		{
			for (int i = 0; i < pos; i++)
			{
				if (i)
					printf(" ");
				printf("%s", res[i]);
			}
			printf('\n');
		}
	}
	resolv(arg + 1, res, pos, sum, add);
	res[pos] = arg[0];
	resolv(arg + 1, res, pos + 1, sum, atoi(arg[0]));
}
int	main(int ac, char **argv)
{
	int		sum;
	int		len;
	char	**res;

	sum = atoi(argv[1]);
	len = ac - 2;
	res = calloc(ac, sizeof(char *));
	solve(argv + 2, res, 0, sum, 0);
}
