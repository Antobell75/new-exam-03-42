#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 8

int ft_strncmp(char *str, const char *str1, size_t len)
{
	int i = 0;

	while(str[i] && str1[i] && str[i] == str1[i] && i < len)
		i++;
	if (i == len)
		return (0);
	return (1);
}

void replace(char *result, const char *word, size_t total_bytes)
{
    size_t len = strlen(word);

    if (len == 0)
        return;
    size_t i = 0;
    while (i < total_bytes)
    {
        if (i + len <= total_bytes &&
            ft_strncmp(result + i, word, len) == 0)
         {
            for (size_t j = 0; j < len; j++)
                result[i + j] = '*';
            i += len;
        }
        else
            i++;
    }
}
int main(int argc, char **argv)
{
    if (argc != 2 || strlen(argv[1]) == 0)
        return (1);

    const char *word = argv[1];
    char    buffer[BUFFER_SIZE];
    char    *result = NULL;
    char    *tmp = NULL;
    ssize_t bytes_read;
    size_t  total_bytes = 0;

    while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
    {
        tmp = realloc(result, total_bytes + (size_t)bytes_read);
        if (!tmp)
            return (free(result), 1);
        result = tmp;
        for (size_t j = 0; j < bytes_read; j++)
			result[total_bytes + j] = buffer[j];
        total_bytes += (size_t)bytes_read;
    }
    if (bytes_read < 0)
        return (free(result), 1);
    if (result == NULL)
        return (0);
    tmp = realloc(result, total_bytes + 1);
    if (!tmp)
        return (free(result), 1);
    result = tmp;
    result[total_bytes] = '\0';
    replace(result, word, total_bytes);
    printf("%s", result);
    free(result);
    return (0);
}
