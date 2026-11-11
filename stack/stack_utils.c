/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:34:17 by jcole             #+#    #+#             */
/*   Updated: 2026/10/29 17:55:17 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *s)
{
	int		size;
	t_node	*cur;

	size = 0;
	cur = s->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}

int	find_min_pos(t_stack *s)
{
	int		pos;
	int		min_pos;
	int		min;
	t_node	*cur;

	pos = 0;
	min_pos = 0;
	min = s->head->value;
	cur = s->head;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (min_pos);
}

int	find_max_pos(t_stack *s)
{
	int		pos;
	int		max_pos;
	int		max;
	t_node	*cur;

	pos = 0;
	max_pos = 0;
	max = s->head->rank;
	cur = s->head;
	while (cur)
	{
		if (cur->rank > max)
		{
			max = cur->rank;
			max_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (max_pos);
}

void	assign_ranks(t_stack *a)
{
	t_node	*cur;
	t_node	*other;
	int		count;

	cur = a->head;
	while (cur)
	{
		count = 0;
		other = a->head;
		while (other)
		{
			if (other->value < cur->value)
				count++;
			other = other->next;
		}
		cur->rank = count;
		cur = cur->next;
	}
}

int	get_chunk_size(int n)
{
	int	size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
}
