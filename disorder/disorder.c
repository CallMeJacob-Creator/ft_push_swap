/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcole <jcole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 02:17:23 by marvin            #+#    #+#             */
/*   Updated: 2026/10/29 16:18:11 by jcole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(const t_stack *stack)
{
	const t_node	*current;
	const t_node	*compare;
	int				mistakes;
	int				total_pairs;

	if (!stack || !stack->head || !stack->head->next)
		return (0.0);
	current = stack->head;
	mistakes = 0;
	total_pairs = 0;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value > compare->value)
				mistakes += 1;
			total_pairs += 1;
			compare = compare->next;
		}
		current = current->next;
	}
	return ((double)mistakes / total_pairs);
}
