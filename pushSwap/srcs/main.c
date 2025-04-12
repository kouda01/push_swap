#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*arr;
	int		size;

	if (argc < 2)
		return (0);
	arr = parse_args(argc, argv, &size);
	if (!arr)
		error_exit();
	stack_a = create_stack();
	stack_b = create_stack();
	if (!stack_a || !stack_b || !init_stack_a(stack_a, arr, size))
	{
		free_resources(stack_a, stack_b, arr);
		error_exit();
	}
	normalize_stack(stack_a, arr, size);
	index_stack(stack_a);
	if (!is_sorted(stack_a))
	{
		if (size <= 5)
			sort_small_stack(stack_a, stack_b, size);
		else
			radix_sort(stack_a, stack_b);
	}
	free_resources(stack_a, stack_b, arr);
	return (0);
}