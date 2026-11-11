/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcole <jcole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:46:30 by jcole             #+#    #+#             */
/*   Updated: 2026/10/30 15:30:33 by jcole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench->disorder < 0.2)
		simple_sort(a, b, bench);
	else if (bench->disorder >= 0.2 && bench->disorder < 0.5)
		medium_sort(a, b, bench);
	else if (bench->disorder >= 0.5)
		complex_sort(a, b, bench);
}

void	sort_stack(t_stack *a, t_stack *b, int strategy, t_bench *bench)
{
	bench->disorder = compute_disorder(a);
	bench->strategy = strategy;
	if (bench->disorder == 0.0)
		return ;
	if (stack_size(a) < 2)
		return ;
	if (stack_size(a) == 2)
	{
		if (a->head->value > a->tail->value)
			return (sa(a, bench));
	}
	if (stack_size(a) <= 5)
	{
		simple_sort(a, b, bench);
		return ;
	}
	if (strategy == 1)
		simple_sort(a, b, bench);
	else if (strategy == 2)
		medium_sort(a, b, bench);
	else if (strategy == 3)
		complex_sort(a, b, bench);
	else
		adaptive_sort(a, b, bench);
}
