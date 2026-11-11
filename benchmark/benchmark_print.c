/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:06:36 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/29 13:06:38 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(double disorder)
{
	int	scale;
	int	whole;
	int	decimal;

	scale = (int)(disorder * 10000 + 0.5);
	whole = scale / 100;
	decimal = scale % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	if (decimal < 10)
		ft_putstr_fd(".0", 2);
	else
		ft_putchar_fd('.', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_strategy(const t_bench *bench)
{
	if (bench->strategy == 1)
		ft_putstr_fd("[bench] strategy: Simple / O(n²)\n", 2);
	else if (bench->strategy == 2)
		ft_putstr_fd("[bench] strategy: Medium / O(n√n)\n", 2);
	else if (bench->strategy == 3)
		ft_putstr_fd("[bench] strategy: Complex / O(n log n)\n", 2);
	else
	{
		if (bench->disorder < 0.2)
			ft_putstr_fd("[bench] strategy: Adaptive / O(n²)\n", 2);
		else if ((bench->disorder >= 0.2) && (bench->disorder < 0.5))
			ft_putstr_fd("[bench] strategy: Adaptive / O(n√n)\n", 2);
		else
			ft_putstr_fd("[bench] strategy: Adaptive / O(n log n)\n", 2);
	}
}

void	print_op(const char *name, int count)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
}

void	print_total_ops(const t_bench *bench)
{
	int	total_ops;

	total_ops = bench->sa + bench->sb + bench->ss + bench->pa
		+ bench->pb + bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr;
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putstr_fd("\n", 2);
}

void	print_statistics(const t_bench *bench)
{
	ft_putstr_fd("[bench] ", 2);
	print_op("sa", bench->sa);
	print_op("  sb", bench->sb);
	print_op("  ss", bench->ss);
	print_op("  pa", bench->pa);
	print_op("  pb", bench->pb);
	ft_putstr_fd("\n[bench] ", 2);
	print_op("ra", bench->ra);
	print_op("  rb", bench->rb);
	print_op("  rr", bench->rr);
	print_op("  rra", bench->rra);
	print_op("  rrb", bench->rrb);
	print_op("  rrr", bench->rrr);
	ft_putstr_fd("\n", 2);
}
