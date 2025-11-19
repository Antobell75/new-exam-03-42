#include <stdio.h>
#include <stdlib.h>

int	is_safe(int *position, int row, int col)
{
	int	row_prev;

	for (int col_prev = 0; col_prev < col; col_prev++)
	{
		row_prev = position[col_prev];
		if (row == row_prev || row + col == row_prev
			+ col_prev || row - col == row_prev - col_prev)
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
