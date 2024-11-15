/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:37:42 by pibernar          #+#    #+#             */
/*   Updated: 2024/03/05 14:50:41 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ft_size_ptr(long unsigned int ptr)
{
	int	size;

	size = 0;
	while (ptr / 16)
	{
		ptr /= 16;
		size++;
	}
	size++;
	return (size);
}

static void	ft_puthexa(int fd, long unsigned int p)
{
	if (p / 16)
		ft_puthexa(fd, p / 16);
	p %= 16;
	if (p <= 9)
		ft_putchar_fd('0' + p, fd);
	else
		ft_putchar_fd('a' - 10 + p, fd);
}

int	ft_printptr(int fd, long unsigned int p)
{
	int	res;

	res = ft_size_ptr(p);
	if (p == 0)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putstr_fd("0x", fd);
	res += 2;
	ft_puthexa(fd, p);
	return (res);
}
