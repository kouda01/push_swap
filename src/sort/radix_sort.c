#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_max_bits(t_stack *stack)
{
	int		max_bits;
	int		max_num;
	t_stack	*tmp;

	max_bits = 0;
	max_num = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max_num)
			max_num = tmp->index;
		tmp = tmp->next;
	}
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp;
	int			i;
	int			j;
	int			size;
	int			max_bits;

	size = ft_stack_size(*stack_a);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			tmp = *stack_a;
			if (((tmp->index >> i) & 1) == 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b, 1);
			j++;
		}
		while (ft_stack_size(*stack_b) > 0)
			pa(stack_a, stack_b, 1);
		i++;
	}
}