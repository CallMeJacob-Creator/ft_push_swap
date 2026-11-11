/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:36:14 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/10/21 12:15:03 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	unsigned long long	p;
	int					count;

	p = (unsigned long long)ptr;
	count = 0;
	if (!ptr)
	{
		count += print_str("(nil)");
		return (count);
	}
	count += print_str("0x");
	count += print_lower_hex(p);
	return (count);
}
