#include "../includes/push_swap.h"

void    ra(t_stack *a, int print)
{
    t_node  *first;
    t_node  *last;

    if (!a || a->size < 2)
        return ;
    first = a->top;
    a->top = first->next;
    last = first;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    if (print)
        write(1, "ra\n", 3);
}

void    rb(t_stack *b, int print)
{
    t_node  *first;
    t_node  *last;

    if (!b || b->size < 2)
        return ;
    first = b->top;
    b->top = first->next;
    last = first;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
    if (print)
        write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a, 0);
    rb(b, 0);
    write(1, "rr\n", 3);
}