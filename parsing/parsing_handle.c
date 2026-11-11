/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:05:26 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/21 12:06:56 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	same_strings(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] && str2[i]) && (str1[i] == str2[i]))
		i++;
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	return (0);
}

int	is_bench(const char *str, int *bench)
{
	if (!same_strings(str, "--bench"))
		return (0);
	if (*bench == 0)
	{
		*bench = 1;
		return (1);
	}
	return (-1);
}

int	is_strategy(const char *str)
{
	int	strategy_num;

	strategy_num = 0;
	if (same_strings(str, "--simple"))
		strategy_num = 1;
	if (same_strings(str, "--medium"))
		strategy_num = 2;
	if (same_strings(str, "--complex"))
		strategy_num = 3;
	if (same_strings(str, "--adaptive"))
		strategy_num = 4;
	return (strategy_num);
}

int	handle_strategy(const char *arg, int *strategy, int *strategy_selected)
{
	int	result;

	result = is_strategy(arg);
	if (result == 0)
		return (0);
	if (*strategy_selected == 1)
		return (-1);
	*strategy = result;
	*strategy_selected = 1;
	return (1);
}
