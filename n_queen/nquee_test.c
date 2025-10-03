/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nquee_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:34:38 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/18 16:36:08 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8

int		board[N];

int	is_safe(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i] == col || abs(board[i] - col) == abs(i - row))
			return (0);
	}
	return (1);
}
void	print(void)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d",board[i]);
	}
	printf("\n");
}
void	solve(row)
{
	if (row == N)
	{
		print();
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
	return ;
}

int main()
{
	solve(0);
}

