/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:39:26 by pibernar          #+#    #+#             */
/*   Updated: 2024/03/05 14:51:02 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h" 

static	int	ft_size_hexa(unsigned int n)
{
	int	size;

	size = 0;
	while (n / 16)
	{
		n /= 16;
		size++;
	}
	size++;
	return (size);
}

int	ft_printhexa(int fd, unsigned int n, char c)
{
	int	ret;

	ret = ft_size_hexa(n);
	if (n / 16)
		ft_printhexa(fd, n / 16, c);
	n %= 16;
	if (n <= 9)
		ft_putchar_fd('0' + n, fd);
	else
		ft_putchar_fd(c - 33 + n, fd);
	return (ret);
}
