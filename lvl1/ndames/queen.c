/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbellar <anbellar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:38:30 by anbellar          #+#    #+#             */
/*   Updated: 2025/11/19 23:48:01 by anbellar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_safe(int *pos, int col, int row)
{
	int row_p;

	for (int col_p = 0; col_p < col; col_p++)
	{
		row_p = pos[col_p];
		if (row == row_p || col + row == row_p + col_p || row - col == row - col)
			return (0);
	}
	return (1);
}

void	solve(int *position, int col, int i)
{
	if (i == col)
	{
		for (int j = 0; j < i; j++)
		{
			if (j > 0)
				fprintf(stdout, " ");
			fprintf(stdout, "%d", position[j]);
		}
		fprintf(stdout, "\n");
		return ;
	}
	for (int row = 0; row < i; row++)
	{
		if (is_safe(position, row, col))
		{
			position[col] = row;
			solve(position, col + 1, i);
		}
	}
}

int	main(int ac, char **argv)
{
	int	num;
	int	*ptr;

	if (ac != 2)
		return (0);
	num = atoi(argv[1]);
	if (num <= 0)
		return (0);
	if (num == 2 || num == 3)
		return (1);
	ptr = malloc(sizeof(int) * num);
	if (!ptr)
		return (1);
	solve(ptr, 0, num);
	free(ptr);
	return (0);
}
