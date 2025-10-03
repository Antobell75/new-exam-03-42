/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_qeen_soluce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:32:47 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/18 16:34:22 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef N
#define N 8
#endif

int		board[N];

int	is_safe(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i] == col ||abs(board[i] - col) == abs(i - row))
			return (0);
	}
	return (1);
}

void	print_solution(void)
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i] == j)
				printf("%d",j);
			else
				printf("");
		}
	}
	printf("\n");
}

void	solve(int row)
{
	if (row == N)
	{
		print_solution();
		return ;
	}
	for (int col = 0; col < N; col++)
	{
		if (is_safe(row, col))
		{
			board[row] = col;
			solve(row + 1);
		}
	}
}

int	main(void)
{
	solve(0);
	return (0);
}
