#include "../includes/push_swap.h"

int get_min_position(t_stack *stack)
{
    t_node *current = stack->top;
    int min = current->value;
    int min_pos = 0;
    int pos = 0;

    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (min_pos);
}

void    sort_two(t_stack *a)
{
    if (a->top->value > a->top->next->value)
        sa(a, 1);
}

void    sort_three(t_stack *stack_a)
{
    int a;
    int b;
    int c;

    a = stack_a->top->value;
    b = stack_a->top->next->value;
    c = stack_a->top->next->next->value;
    if (a > b && b < c && a < c)
		sa(stack_a, 1);
	else if (a > b && b > c)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, 1);
}