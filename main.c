/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:13:37 by marvin            #+#    #+#             */
/*   Updated: 2026/10/30 16:38:42 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exit_error(t_stack *a)
{
	free_stack(a);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

static int	run_sort(t_stack *a, t_stack *b, int strategy, int bench_flag)
{
	t_bench	stats;

	stats = (t_bench){0};
	sort_stack(a, b, strategy, &stats);
	if (bench_flag)
		benchmark(&stats);
	free_stack(a);
	free_stack(b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		strategy;
	int		bench_flag;
	int		start;

	if (argc == 1)
		return (0);
	init_stack(&a);
	init_stack(&b);
	strategy = 4;
	bench_flag = 0;
	start = parse_option(argc, argv, &strategy, &bench_flag);
	if (start == -1 || start == argc)
		return (exit_error(&a));
	if (parse_numbers(argc, argv, start, &a) == -1)
		return (exit_error(&a));
	return (run_sort(&a, &b, strategy, bench_flag));
}
