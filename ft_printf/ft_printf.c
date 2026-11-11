/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:17:07 by yaalmoui          #+#    #+#             */
/*   Updated: 2026/09/16 21:03:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char *s, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX", *format))
				i += check_type(format, args);
			else if (*format == '%')
				i += print_char('%');
		}
		else
			i += print_char(*format);
		format++;
	}
	va_end(args);
	return (i);
}

static int	check_type(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += print_char(va_arg(args, int));
	else if (*format == 's')
		i += print_str(va_arg(args, char *));
	else if (*format == 'p')
		i += print_pointer(va_arg(args, void *));
	else if (*format == 'i' || *format == 'd')
		i += print_digit(va_arg(args, int));
	else if (*format == 'u')
		i += print_digit(va_arg(args, unsigned int));
	else if (*format == 'x')
		i += print_hex(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		i += print_hex(va_arg(args, unsigned int), 1);
	return (i);
}
