/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:03:27 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/29 13:10:04 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_option(int argc, char **argv, int *strategy, int *bench)
{
	int	i;
	int	selected;
	int	result;

	i = 1;
	selected = 0;
	while (i < argc)
	{
		result = is_bench(argv[i], bench);
		if (result == 0)
			result = handle_strategy(argv[i], strategy, &selected);
		if (result == -1)
			return (-1);
		if (result == 0)
		{
			if (argv[i][0] == '-' && argv[i][1] == '-')
				return (-1);
			return (i);
		}
		i++;
	}
	return (i);
}

static int	add_number(char *str, t_stack *stack)
{
	int		number;
	t_node	*node;

	if (!is_valid_number(str))
		return (-1);
	if (!safe_atoi(str, &number))
		return (-1);
	if (has_duplicate(stack, number))
		return (-1);
	node = new_node(number);
	if (!node)
		return (-1);
	push_back(stack, node);
	return (1);
}

static int	parse_tokens(char **tokens, t_stack *stack)
{
	int	j;

	j = 0;
	while (tokens[j])
	{
		if (add_number(tokens[j], stack) == -1)
			return (-1);
		j++;
	}
	return (1);
}

int	parse_numbers(int argc, char **argv, int start, t_stack *stack)
{
	char	**tokens;
	int		i;

	i = start;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
		{
			free_split(tokens);
			free_stack(stack);
			return (-1);
		}
		if (parse_tokens(tokens, stack) == -1)
		{
			free_split(tokens);
			free_stack(stack);
			return (-1);
		}
		free_split(tokens);
		i++;
	}
	return (1);
}
