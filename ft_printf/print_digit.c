/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:12:38 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/09/16 14:39:13 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count += 11;
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			count += print_char('-');
		}
		if (n > 9)
			count += print_digit(n / 10);
		count += print_char((n % 10) + '0');
	}
	return (count);
}
