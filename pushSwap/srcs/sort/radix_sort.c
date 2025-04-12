#include "../includes/push_swap.h"

void    index_stack(t_stack *stack)
{
    t_node  *current;
    t_node  *compare;
    int     index;

    current = stack->top;
    while (current)
    {
        index = 0;
        compare = stack->top;
        while (compare)
        {
            if (compare->value < current->value)
                index++;
            compare = compare->next;
        }
        current->value = index;
        current = current->next;
    }
}

int get_max_bits(t_stack *stack)
{
    t_node *current;
    int     max;
    int     max_bits;

    max = 0;
    current = stack->top;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void    radix_sort(t_stack *a, t_stack *b)
{
    int i;
    int j;
    int size;
    int max_bits;

    max_bits = get_max_bits(a);
    size = a->size;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((a->top->value >> i) & 1)
                ra(a, 1);
            else
                pb(a, b);
            j++;
        }
        while (!is_empty(b))
            pa(a, b);
        i++;
    }
}