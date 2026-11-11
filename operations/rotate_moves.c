/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 17:58:15 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/29 14:09:36 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack->head || stack->head == stack->tail)
		return ;
	temp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	push_back(stack, temp);
}

void	ra(t_stack *a, t_bench *bench)
{
	if (!a->head || a->head == a->tail)
		return ;
	rotate(a);
	bench->ra++;
	ft_printf("ra\n");
}

void	rb(t_stack *b, t_bench *bench)
{
	if (!b->head || b->head == b->tail)
		return ;
	rotate(b);
	bench->rb++;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a || !b)
		return ;
	if ((!a->head || a->head == a->tail) && (!b->head || b->head == b->tail))
		return ;
	rotate(a);
	rotate(b);
	bench->rr++;
	ft_printf("rr\n");
}
