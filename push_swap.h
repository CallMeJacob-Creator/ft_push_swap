/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcole <jcole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 15:16:04 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/30 15:57:10 by jcole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_bench
{
	int		pa;
	int		pb;
	int		sa;
	int		sb;
	int		ss;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	double	disorder;
	int		strategy;
}	t_bench;

void	push_front(t_stack *stack, t_node *node);
void	init_stack(t_stack *stack);
void	push_back(t_stack *stack, t_node *node);
t_node	*new_node(int value);
void	free_stack(t_stack *stack);

void	swap(t_stack *stack);
void	sa(t_stack *a, t_bench *bench);
void	sb(t_stack *b, t_bench *bench);
void	ss(t_stack *a, t_stack *b, t_bench *bench);
void	push(t_stack *stack1, t_stack *stack2);
void	pa(t_stack *a, t_stack *b, t_bench *bench);
void	pb(t_stack *a, t_stack *b, t_bench *bench);
void	rotate(t_stack *stack);
void	ra(t_stack *a, t_bench *bench);
void	rb(t_stack *b, t_bench *bench);
void	rr(t_stack *a, t_stack *b, t_bench *bench);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a, t_bench *bench);
void	rrb(t_stack *b, t_bench *bench);
void	rrr(t_stack *a, t_stack *b, t_bench *bench);

int		parse_option(int argc, char **argv, int *strategy, int *bench);
int		is_bench(const char *str, int *bench);
int		is_strategy(const char *str);
int		handle_strategy(const char *arg, int *strategy,
			int *strategy_selected);
int		is_valid_number(const char *str);
int		safe_atoi(const char *str, int *result);
int		has_duplicate(t_stack *stack, int value);
int		parse_numbers(int argc, char **argv, int start, t_stack *stack);
void	free_split(char **tokens);
int		find_min_pos(t_stack *s);
int		find_max_pos(t_stack *s);
int		stack_size(t_stack *s);
int		get_chunk_size(int n);
void	rotate_to_top(t_stack *s, int pos, t_bench *bench);

void	sort_stack(t_stack *a, t_stack *b, int strategy, t_bench *bench);
void	complex_sort(t_stack *a, t_stack *b, t_bench *bench);
void	medium_sort(t_stack *a, t_stack *b, t_bench *bench);
void	simple_sort(t_stack *a, t_stack *b, t_bench *bench);
void	assign_ranks(t_stack *a);

double	compute_disorder(const t_stack *stack);

void	print_disorder(double disorder);
void	print_strategy(const t_bench *bench);
void	print_total_ops(const t_bench *bench);
void	print_op(const char *name, int count);
void	print_statistics(const t_bench *bench);
void	benchmark(t_bench *bench);

#endif
