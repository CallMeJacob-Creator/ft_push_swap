/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:27:13 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/21 12:05:59 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if ((str[i] == '+' || str[i] == '-') && !str[i + 1])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	convert_digit(const char *str, long limit, long *number)
{
	int	digit;

	while (*str)
	{
		digit = *str - '0';
		if (*number > (limit - digit) / 10)
			return (0);
		*number = *number * 10 + digit;
		str++;
	}
	return (1);
}

int	safe_atoi(const char *str, int *result)
{
	long	number;
	long	limit;
	int		sign;

	number = 0;
	limit = INT_MAX;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = -1;
			limit = -(long long)INT_MIN;
		}
		str++;
	}
	if (!convert_digit(str, limit, &number))
		return (0);
	*result = (int)(number * sign);
	return (1);
}

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack->head;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	free_split(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
