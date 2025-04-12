#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int     size;
} t_stack;

/* Stack operations */
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* Stack utils */
t_stack	*create_stack(void);
int		push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		is_empty(t_stack *stack);
int		peek(t_stack *stack);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);

/* Parsing and error handling */
int		*parse_args(int argc, char **argv, int *size);
int		check_duplicates(int *arr, int size);
int		init_stack_a(t_stack *stack_a, int *arr, int size);
void	normalize_stack(t_stack *stack_a, int *arr, int size);
void	free_resources(t_stack *stack_a, t_stack *stack_b, int *arr);
void	error_exit(void);
int		ft_isspace(char c);
int		ft_atoi_safe(char *str, int *num, int *i);
int		count_numbers(char *str);
int		parse_single_arg(char *str, int **arr, int *size);
int		parse_multiple_args(int argc, char **argv, int **arr, int *size);

/* Sorting algorithms */
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b, int size);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
int		get_min_position(t_stack *stack);
int		get_max_bits(t_stack *stack);
void    index_stack(t_stack *stack);

#endif