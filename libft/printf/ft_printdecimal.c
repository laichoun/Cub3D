/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:42:24 by pibernar          #+#    #+#             */
/*   Updated: 2024/03/05 14:48:04 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ft_size_num(int n)
{
	int		size;
	long	num;

	size = 0;
	num = (long)n;
	if (num < 0)
	{
		num *= -1;
		size++;
	}
	while (num / 10)
	{
		size++;
		num /= 10;
	}
	size++;
	return (size);
}

int	ft_printdecimal(int fd, int n)
{
	ft_putnbr_fd(n, fd);
	return (ft_size_num(n));
}
