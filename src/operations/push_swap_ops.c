#include "../includes/push_swap.h"

void	sa(t_stack **stack_a, int print)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_b || !stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (print)
		write(1, "pb\n", 3);
}