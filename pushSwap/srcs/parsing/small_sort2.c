#include "../includes/push_swap.h"

void    sort_four(t_stack *a, t_stack *b)
{
    int min_pos;

    min_pos = get_min_position(a);
    if (min_pos == 1)
        sa(a, 1);
    else if (min_pos == 2)
    {
        ra(a, 1);
        ra(a, 1);
    }
    else if (min_pos == 3)
        rra(a, 1);
    if (is_sorted(a))
        return ;
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

void    sort_five(t_stack *a, t_stack *b)
{
    int min_pos;

    min_pos = get_min_position(a);
    if (min_pos == 1)
        sa(a, 1);
    else if (min_pos == 2)
    {
        ra(a, 1);
        ra(a, 1);
    }
    else if (min_pos == 3)
    {
        rra(a, 1);
        rra(a, 1);
    }
    else if (min_pos == 4)
        rra(a, 1);
    if (is_sorted(a))
        return ;
    pb(a, b);
    sort_four(a, b);
    pa(a, b);
}

void    sort_small_stack(t_stack *a, t_stack *b, int size)
{
    if (size == 2)
        sort_two(a);
    else if (size == 3)
        sort_three(a);
    else if (size == 4)
        sort_four(a, b);
    else if (size == 5)
        sort_five(a, b);
}