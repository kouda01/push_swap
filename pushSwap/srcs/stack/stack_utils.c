#include "../includes/push_swap.h"

t_stack *create_stack(void)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

int push(t_stack *stack, int value)
{
    t_node  *new_node;

    if (!stack)
        return (0);
    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (0);
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
    return (1);
}

int pop(t_stack *stack)
{
    t_node *tmp;
    int     value;

    if (!stack || !stack->top)
        return (0);
    tmp = stack->top;
    value = tmp->value;
    stack->top = tmp->next;
    free(tmp);
    stack->size--;
    return (value);
}

int is_empty(t_stack *stack)
{
    return (!stack || stack->size == 0);
}