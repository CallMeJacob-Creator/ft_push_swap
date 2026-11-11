/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:19:22 by jcole             #+#    #+#             */
/*   Updated: 2026/11/01 16:06:22 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a_to_top(t_stack *a, int pos, t_bench *bench)
{
	int	size;

	size = stack_size(a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, bench);
	}
	else
	{
		while (pos++ < size)
			rra(a, bench);
	}
}

static void	sort_three(t_stack *a, t_bench *bench)
{
	int	x;
	int	y;
	int	z;

	x = a->head->value;
	y = a->head->next->value;
	z = a->tail->value;
	if (x > y && y < z && x < z)
		sa(a, bench);
	else if (x > y && y > z)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (x > y && y < z && x > z)
		ra(a, bench);
	else if (x < y && y > z && x < z)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (x < y && y > z && x > z)
		rra(a, bench);
}

void	simple_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	int	size;

	size = stack_size(a);
	if (size == 2 && a->head->value > a->tail->value)
		sa(a, bench);
	if (size < 3)
		return ;
	while (stack_size(a) > 3)
	{
		rotate_a_to_top(a, find_min_pos(a), bench);
		pb(a, b, bench);
	}
	sort_three(a, bench);
	while (b->head)
		pa(a, b, bench);
}
