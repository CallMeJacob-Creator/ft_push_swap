/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:58:09 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/09/16 15:25:20 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lower_hex(unsigned long n)
{
	char	*symbols;
	int		count;

	symbols = "0123456789abcdef";
	count = 0;
	if (n > 15)
		count += print_lower_hex(n / 16);
	count += print_char(symbols[n % 16]);
	return (count);
}

int	print_upper_hex(unsigned long n)
{
	char	*symbols;
	int		count;

	symbols = "0123456789ABCDEF";
	count = 0;
	if (n > 15)
		count += print_upper_hex(n / 16);
	count += print_char(symbols[n % 16]);
	return (count);
}

int	print_hex(unsigned long n, int x)
{
	int	count;

	count = 0;
	if (x == 0)
		count += print_lower_hex(n);
	if (x == 1)
		count += print_upper_hex(n);
	return (count);
}
