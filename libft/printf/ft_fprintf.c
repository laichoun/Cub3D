/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:12:11 by pibernar          #+#    #+#             */
/*   Updated: 2024/10/23 21:06:07 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ft_format(int fd, char c, va_list args)
{
	if (c == 'c')
		return (ft_printchar(fd, va_arg(args, int)));
	if (c == 's')
		return (ft_printstr(fd, va_arg(args, char *)));
	if (c == 'p')
		return (ft_printptr(fd, va_arg(args, long unsigned int)));
	if (c == 'd' || c == 'i')
		return (ft_printdecimal(fd, va_arg(args, int)));
	if (c == 'u')
		return (ft_printunint(fd, va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_printhexa(fd, va_arg(args, unsigned int), 'x'));
	if (c == 'X')
		return (ft_printhexa(fd, va_arg(args, unsigned int), 'X'));
	if (c == '%')
		return (ft_printpercent(fd));
	return (0);
}

int	ft_fprintf(int fd, const char *str, ...)
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
			input_size += ft_format(fd, *str, args);
		}
		else
			input_size += ft_printchar(fd, (int)*str);
		str++;
	}
	va_end(args);
	return (input_size);
}
