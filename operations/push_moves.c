/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:38:17 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/29 16:51:13 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack1, t_stack *stack2)
{
	t_node	*temp;

	if (stack1->head == NULL)
		return ;
	if (stack1->head == stack1->tail && stack2->head == NULL)
	{
		stack2->head = stack1->head;
		stack2->tail = stack1->tail;
		stack1->head = NULL;
		stack1->tail = NULL;
	}
	else if (stack1->head == stack1->tail && stack2->head)
	{
		push_front(stack2, stack1->head);
		stack1->head = NULL;
		stack1->tail = NULL;
	}
	else
	{
		temp = stack1->head->next;
		push_front(stack2, stack1->head);
		stack1->head = temp;
		stack1->head->prev = NULL;
	}
}

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a->head)
		return ;
	push(a, b);
	ft_printf("pb\n");
	bench->pb++;
}

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!b->head)
		return ;
	push(b, a);
	ft_printf("pa\n");
	bench->pa++;
}
