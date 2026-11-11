/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 18:27:53 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/29 14:33:33 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack->head || stack->head == stack->tail)
		return ;
	temp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	push_front(stack, temp);
}

void	rra(t_stack *a, t_bench *bench)
{
	if (!a->head || a->head == a->tail)
		return ;
	reverse_rotate(a);
	ft_printf("rra\n");
	bench->rra++;
}

void	rrb(t_stack *b, t_bench *bench)
{
	if (!b->head || b->head == b->tail)
		return ;
	reverse_rotate(b);
	ft_printf("rrb\n");
	bench->rrb++;
}

void	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	if ((!a->head || a->head == a->tail) && (!b->head || b->head == b->tail))
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
	bench->rrr++;
}
