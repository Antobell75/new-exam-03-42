

void	put_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int	str_equal(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (a[i] == b[i]);
}

int	already_seen(char seen[][256], int count, const char *str)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (str_equal(seen[i], str))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid(const char *str)
{
	int	bal;
	int i;

	bal = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			bal++;
		else if (str[i] == ')')
		{
			bal--;
			if (bal < 0)
				return (0);
		}
		i++;
	}
	return (bal == 0);
}

void	mark_excess(char *str, int *left, int *right)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	*left = 0;
	*right = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
			{
				str[i] = '_';
				(*right)++;
			}
		}
		i++;
	}
	i--;
	while (i >= 0 && open > 0)
	{
		if (str[i] == '(')
		{
			str[i] = '_';
			(*left)++;
			open--;
		}
		i--;
	}
}
void	str_copy(char *dst, const char *src, int max)
{
	int	i;

	i = 0;
	while (src[i] && i < max - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
void	solve(char *str, int index, int left, int right, char seen[][256],
		int *count_seen)
{
	char	c;
	char	old;

	if (str[index] == '\0')
	{
		if (left == 0 && right == 0 && is_valid(str) && !already_seen(seen,
				*count_seen, str))
		{
			put_line(str);
			str_copy(seen[*count_seen], str, 256);
			(*count_seen)++;
		}
		return ;
	}
	c = str[index];
	if ((c == '(' && left > 0) || (c == ')' && right > 0))
	{
		old = str[index];
		str[index] = '_';
		dfs(str, index + 1, left - (c == '(' ? 1 : 0), right
			- (c == ')' ? 1 : 0), seen, count_seen);
		str[index] = old;
	}
	dfs(str, index + 1, left, right, seen, count_seen);
}

int	main(int ac, char **av)
{
	int		i;
	char	seen[1000][256];
	int		count_seen;

	if (ac != 2)
		return (1);
	i = 0;
	int left, right;
	mark_excess(av[1], &left, &right);
	count_seen = 0;
	solve(av[1], 0, left, right, seen, &count_seen);
	return (0);
}
