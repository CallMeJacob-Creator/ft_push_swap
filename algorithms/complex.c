/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:19:16 by jcole             #+#    #+#             */
/*   Updated: 2026/11/01 15:56:58 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_binary(t_stack *a)
{
	int	maxsize;
	int	bits;

	maxsize = stack_size(a) - 1;
	bits = 0;
	while (maxsize > 0)
	{
		bits++;
		maxsize >>= 1;
	}
	return (bits);
}

static void	assign_complex_ranks(t_stack *a)
{
	t_node	*cur;
	t_node	*other;

	cur = a->head;
	while (cur)
	{
		cur->rank = 0;
		other = a->head;
		while (other)
		{
			if (other->value < cur->value)
				cur->rank++;
			other = other->next;
		}
		cur = cur->next;
	}
}

static void	radix_algo(t_stack *a, t_stack *b, t_bench *bench)
{
	int	curbit;
	int	digit;
	int	i;
	int	size;
	int	max_bits;

	size = stack_size(a);
	max_bits = max_binary(a);
	curbit = 0;
	while (curbit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			digit = (a->head->rank >> curbit) & 1;
			if (digit == 0)
				pb(a, b, bench);
			else
				ra(a, bench);
			i++;
		}
		while (b->head != NULL)
			pa(a, b, bench);
		curbit++;
	}
}

void	complex_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	assign_complex_ranks(a);
	radix_algo(a, b, bench);
}
