#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 8

int ft_strncmp(char *str, const char *str1, size_t len)
{
	size_t i = 0;
	
	while(str[i] && str[i] && i < len && str[i] == str1[i])
		i++;
	if (i == len)
		return (0);
	return (1);
}

void replace(char *result, const char *word, size_t total_bytes)
{
	size_t len = strlen(word);
	size_t i = 0;

	while (i < total_bytes)
	{
		if (i + len <= total_bytes && ft_strncmp(result + i, word, len) == 0)
		{
			for (size_t j = 0; j < len; j++)
				result[i + j] = '*';
			i += len;
		}
		else
			i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2 || strlen(av[1]) == 0)
		return (1);
	
	const char *word = av[1];
	char buffer[BUFFER_SIZE];
	char *result = NULL;
	char *tmp = NULL;
	ssize_t bytes_read;
	size_t total_read = 0;

	while((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		tmp = realloc(result, total_read + (size_t)bytes_read);
		if (!tmp)
			return (free(result), 1);
		result = tmp;
		for (size_t i = 0; i < bytes_read; i++)
			result[total_read + i] = buffer[i];
		total_read += (size_t)bytes_read;
	}
	if (bytes_read < 0)
		return (free(result), 1);
	if (result == NULL)
		return (0);
	tmp = realloc(result, total_read + 1);
	if (!tmp)
		return (free(result), 1);
	result = tmp;
	result[total_read] = '\0';
	replace(result, word, total_read);
	printf("%s", result);
	free(result);
	return (0);
}
