#include "../includes/push_swap.h"

void    pa(t_stack *a, t_stack *b)
{
    int value;

    if (!b || !b->top)
        return ;
    value = b->top->value;
    pop(b);
    push(a, value);
    write(1, "pa\n", 3);
}

void    pb(t_stack *a, t_stack *b)
{
    int value;

    if (!a || !a->top)
        return ;
    value = a->top->value;
    pop(a);
    push(b, value);
    write(1, "pb\n", 3);
}