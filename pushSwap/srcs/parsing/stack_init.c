#include "../includes/push_swap.h"

int init_stack_a(t_stack *a, int *arr, int size)
{
    int i;

    i =  size - 1;
    while (i >= 0)
    {
        if (!push(a, arr[i]))
            return (0);
        i--;
    }
    return (1);
}

void    normalize_stack(t_stack *a, int *arr, int size)
{
    t_node  *current;
    int     i;
    int     pos;

    current = a->top;
    while (current)
    {
        i = 0;
        pos = 0;
        while (i < size)
        {
            if (arr[i] < current->value)
                pos++;
            i++;
        }
        current->value = pos;
        current = current->next;
    }
}

void    error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}