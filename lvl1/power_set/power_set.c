#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void    print_set(char **str, int *include, int size)
{
    int    flag;

    flag = 1;
    for (int i = 0; i < size; i++)
    {
        if (include[i])
        {
            if (!flag)
                printf(" ");
            printf("%s", str[i]);
            flag = 0;
        }
    }
    printf("\n");
}

void    powerset(char **str, int *include, int index, int size, int sum,
        int target)
{
    if (index == size)
    {
        if (sum == target)
            print_set(str, include, size);
        return ;
    }
    include[index] = 0;
    powerset(str, include, index + 1, size, sum, target);
    include[index] = 1;
    powerset(str, include, index + 1, size, sum + atoi(str[index]), target);
}

int    main(int ac, char **av)
{
    char    **str;
    int        target;
    int        size;

    if (ac < 3)
        return (0);
    str = &av[2];
    target = atoi(av[1]);
    size = ac - 2;
	int include[size];
    powerset(str, include, 0, size, 0, target);
    return (0);
}
