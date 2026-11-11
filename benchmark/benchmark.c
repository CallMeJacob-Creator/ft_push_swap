/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:06:23 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/29 13:06:27 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	benchmark(t_bench *bench)
{
	print_disorder(bench->disorder);
	print_strategy(bench);
	print_total_ops(bench);
	print_statistics(bench);
}
