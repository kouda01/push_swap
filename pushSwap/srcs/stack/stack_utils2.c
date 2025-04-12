#include "../includes/push_swap.h"

int peek(t_stack *stack)
{
    if (!stack || !stack->top)
        return (0);
    return (stack->top->value);
}

int is_sorted(t_stack *stack)
{
    t_node  *current;
    t_node  *next;

    if (!stack || !stack->top || stack->size <= 1)
        return (1);
    current = stack->top;
    while (current->next)
    {
        next = current->next;
        if (current->value > next->value)
            return (0);
        current = next;
    }
    return (1);
}

void    free_stack(t_stack *stack)
{
    t_node  *current;
    t_node  *next;

    if (!stack)
        return ;
    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

void    free_resources(t_stack *a, t_stack *b, int *arr)
{
    if (a)
        free_stack(a);
    if (b)
        free_stack(b);
    if (arr)
        free(arr);
}