#include "../includes/push_swap.h"

int ft_isspace(char c)
{
    return (c == ' '|| c == '\t' || c == '\n'||
        c == '\v'|| c == '\f' || c == '\r');
}

int ft_atoi_safe(char *str, int *num, int *i)
{
    long    result;
    int     sign;

    result = 0;
    sign = 1;
    if (str[*i] == '-' || str[*i] == '+')
    {
        if (str[*i] == '-')
            sign = -1;
        (*i)++;
    }
    if (!str[*i] || str[*i] < '0' || str[*i] > '9')
        return (0);
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        result = result * 10 + (str[*i] - '0');
        if ((result > 2147483647 && sign == 1) || (result > 2147483648 && sign == -1))
            return (0);
        (*i)++;
    }
    *num = (int)(result * sign);
    return (1);
}

int count_numbers(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if (!str || !*str)
        return (-1);
    while (str[i])
    {
        while (ft_isspace(str[i]))
            i++;
        if (str[i])
        {
            count++;
            if (str[i] == '-' || str[i] == '+')
                i++;
            while (str[i] >= '0' && str[i] <= '9')
                i++;
            if (str[i] && !ft_isspace(str[i]))
                return (-1);
        }
    }
    return (count);
}