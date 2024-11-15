/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:12:11 by pibernar          #+#    #+#             */
/*   Updated: 2024/10/23 21:05:52 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_printchar(1, va_arg(args, int)));
	if (c == 's')
		return (ft_printstr(1, va_arg(args, char *)));
	if (c == 'p')
		return (ft_printptr(1, va_arg(args, long unsigned int)));
	if (c == 'd' || c == 'i')
		return (ft_printdecimal(1, va_arg(args, int)));
	if (c == 'u')
		return (ft_printunint(1, va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_printhexa(1, va_arg(args, unsigned int), 'x'));
	if (c == 'X')
		return (ft_printhexa(1, va_arg(args, unsigned int), 'X'));
	if (c == '%')
		return (ft_printpercent(1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		input_size;

	va_start(args, str);
	input_size = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			input_size += ft_format(*str, args);
		}
		else
		{
			ft_putchar_fd((int)*str, 1);
			input_size++;
		}
		str++;
	}
	va_end(args);
	return (input_size);
}
