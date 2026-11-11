/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:39:44 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/09/16 11:11:22 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
