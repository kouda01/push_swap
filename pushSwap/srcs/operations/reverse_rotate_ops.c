#include "../includes/push_swap.h"

void    rra(t_stack *a, int print)
{
    t_node  *last;
    t_node  *prev;

    if (!a || a->size < 2)
        return ;
    prev = NULL;
    last = a->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = a->top;
    a->top = last;
    if (print)
        write(1, "rra\n", 4);
}

void    rrb(t_stack *b, int print)
{
    t_node *last;
    t_node *prev;

    if (!b || b->size < 2)
        return ;
    prev = NULL;
    last = b->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = b->top;
    if (print)
        write(1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b)
{
    rra(a, 0);
    rrb(b, 0);
    write(1, "rrr\n", 4);
}