/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:46:50 by jcole             #+#    #+#             */
/*   Updated: 2026/11/01 16:03:45 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_stack *s, int pos, t_bench *bench)
{
	int	size;

	size = stack_size(s);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(s, bench);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(s, bench);
			pos++;
		}
	}
}

static void	push_chunk(t_stack *a, t_stack *b, int high, t_bench *bench)
{
	while (stack_size(b) <= high)
	{
		if (a->head->rank <= high)
			pb(a, b, bench);
		else
			ra(a, bench);
	}
}

static void	push_phase(t_stack *a, t_stack *b, t_bench *bench)
{
	int	n;
	int	size;
	int	low;
	int	high;

	n = stack_size(a);
	size = get_chunk_size(n);
	low = 0;
	while (low < n)
	{
		high = low + size - 1;
		if (high > n - 1)
			high = n - 1;
		push_chunk(a, b, high, bench);
		low = low + size;
	}
}

static void	pull_phase(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;

	while (b->head != NULL)
	{
		pos = find_max_pos(b);
		rotate_to_top(b, pos, bench);
		pa(a, b, bench);
	}
}

void	medium_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	assign_ranks(a);
	push_phase(a, b, bench);
	pull_phase(a, b, bench);
}
