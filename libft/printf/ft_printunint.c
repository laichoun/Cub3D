/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:02:41 by pibernar          #+#    #+#             */
/*   Updated: 2024/03/05 13:31:02 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ft_size_num(unsigned int n)
{
	int	size;

	size = 1;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	ft_putuint(int fd, unsigned int n)
{
	if (n / 10)
		ft_putuint(fd, n / 10);
	ft_putchar_fd('0' + n % 10, fd);
}

int	ft_printunint(int fd, unsigned int n)
{
	ft_putuint(fd, n);
	return (ft_size_num(n));
}
