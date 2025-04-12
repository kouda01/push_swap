#include "../includes/push_swap.h"

void    sa(t_stack * a, int print)
{
    int tmp;

    if (!a || a->size < 2)
        return ;
    tmp = a->top->value;
    a->top->value = a->top->next->value;
    a->top->next->value = tmp;
    if (print)
        write(1, "sa\n", 3);
}

void    sb(t_stack * b, int print)
{
    int tmp;

    if (!b || b->size < 2)
        return ;
    tmp = b->top->value;
    b->top->value = b->top->next->value;
    b->top->next->value = tmp;
    if (print)
        write(1, "sb\n", 3);
}

void    ss(t_stack *a, t_stack *b)
{
    sa(a, 0);
    sb(b, 0);
    write(1, "ss\n", 3);
}
