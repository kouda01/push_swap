#include "../includes/push_swap.h"

int parse_single_arg(char *str, int **arr, int *size)
{
    int i;
    int j;
    int num;

    *size = count_numbers(str);
    if (*size <= 0)
        return (0);
    *arr = (int *)malloc(sizeof(int) * (*size));
    if (!(*arr))
        return (0);
    i = 0;
    j = 0;
    while (str[i])
    {
        while (ft_isspace(str[i]))
            i++;
        if (str[i])
        {
            if (!ft_atoi_safe(str, &num, &i))
                return (0);
            (*arr)[j++] = num;
        }
    }
    return (1);
}

int parse_multiple_args(int argc, char **argv, int **arr, int *size)
{
    int i;
    int j;
    int num;

    *size = argc - 1;
    *arr = (int *)malloc(sizeof(int) * (*size));
    if (!(*arr))
        return (0);
    i = 1;
    j = 0;
    while (i < argc)
    {
        if (count_numbers(argv[i]) != 1)
        {
            free(*arr);
            return (0);
        }
        j = 0;
        if (!ft_atoi_safe(argv[i], &num, &j))
        {
            free(*arr);
            return (0);
        }
        if (argv[i][j])
            return (0);
        (*arr)[i - 1] = num;
        i++;
    }
    return (1);
}

int check_duplicates(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int *parse_args(int argc, char **argv, int *size)
{
    int *arr;
    int result;

    arr = NULL;
    if (argc < 2)
        return (NULL);
    else if (argc == 2)
        result = parse_single_arg(argv[1], &arr, size);
    else
        result = parse_multiple_args(argc, argv, &arr, size);
    if (!result || !check_duplicates(arr, *size))
    {
        if (arr)
            free(arr);
        return (NULL);
    }
    return (arr);
}