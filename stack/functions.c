/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:09:26 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/29 13:09:29 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->rank = -1;
	return (node);
}

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
}

void	push_front(t_stack *stack, t_node *node)
{
	node->prev = NULL;
	if (stack->head == NULL && stack->tail == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->head->prev = node;
		node->next = stack->head;
		stack->head = node;
	}
}

void	push_back(t_stack *stack, t_node *node)
{
	node->next = NULL;
	if (stack->head == NULL && stack->tail == NULL)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*next;

	if (!stack)
		return ;
	while (stack->head)
	{
		next = stack->head->next;
		free(stack->head);
		stack->head = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
}
