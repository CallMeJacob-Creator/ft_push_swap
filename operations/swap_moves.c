/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:45:50 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/29 14:00:08 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*temp1;
	t_node	*temp2;
	t_node	*temp3;

	if (!stack->head || stack->head == stack->tail)
		return ;
	temp1 = stack->head;
	temp2 = stack->head->next;
	temp3 = temp2->next;
	stack->head = temp2;
	temp2->prev = NULL;
	temp2->next = temp1;
	temp1->prev = temp2;
	temp1->next = temp3;
	if (temp3)
		temp3->prev = temp1;
	if (!temp3)
		stack->tail = temp1;
}

void	sa(t_stack *a, t_bench *bench)
{
	if (!a->head || a->head == a->tail)
		return ;
	swap(a);
	bench->sa++;
	ft_printf("sa\n");
}

void	sb(t_stack *b, t_bench *bench)
{
	if (!b->head || b->head == b->tail)
		return ;
	swap(b);
	bench->sb++;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a || !b)
		return ;
	if ((!a->head || a->head == a->tail) && (!b->head || b->head == b->tail))
		return ;
	swap(a);
	swap(b);
	bench->ss++;
	ft_printf("ss\n");
}
