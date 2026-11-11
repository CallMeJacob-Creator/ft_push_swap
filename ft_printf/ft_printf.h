/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaalmoui <yaalmoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:32:22 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/09/16 15:25:45 by yaalmoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_str(const char *str);
int	print_digit(long n);
int	print_pointer(void *ptr);
int	print_hex(unsigned long n, int x);
int	print_upper_hex(unsigned long n);
int	print_lower_hex(unsigned long n);

#endif
