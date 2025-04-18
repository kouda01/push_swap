/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:05:48 by yel-mako          #+#    #+#             */
/*   Updated: 2025/04/14 10:05:50 by yel-mako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* Stack operations */
void				sa(t_stack **stack_a, int print);
void				pa(t_stack **stack_a, t_stack **stack_b, int print);
void				pb(t_stack **stack_a, t_stack **stack_b, int print);
void				ra(t_stack **stack_a, int print);
void				rra(t_stack **stack_a, int print);

/* Stack utils */
t_stack				*ft_stack_new(int value);
void				ft_stack_add_back(t_stack **stack, t_stack *new);
void				ft_stack_add_front(t_stack **stack, t_stack *new);
int					ft_stack_size(t_stack *stack);
void				ft_stack_clear(t_stack **stack);

/* Parsing utils */
int					ft_atoi_safe(const char *str, int *error);
int					ft_isdigit(int c);
int					ft_isspace(int c);
char				**ft_split(char const *s, char c);
int					ft_strlen(const char *s);
void				free_split(char **split);

/* Sort utils */
void				index_stack(t_stack **stack);
int					is_sorted(t_stack *stack);
void				sort_3(t_stack **stack_a);
void				sort_4(t_stack **stack_a, t_stack **stack_b);
void				sort_small_stack(t_stack **stack_a, t_stack **stack_b);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
int					get_max_bits(t_stack *stack);

/* Error handling */
void				ft_error(t_stack **stack_a, t_stack **stack_b,
						char **split);
int					check_duplicates(t_stack *stack);
int					parse_args(int argc, char **argv, t_stack **stack_a);

#endif
