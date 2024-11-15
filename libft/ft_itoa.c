/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:27:53 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/22 17:07:03 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_init_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	return (size);
}

static char	*ft_get_first_char(char *str, int size)
{
	if (size == 0 && str[1] == '\0')
		str[0] = '0';
	else if (size == 0 && str[1] != '\0')
		str[0] = '-';
	return (str);
}

/*
 * Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 * Return NULL if the allocation fails
*/
char	*ft_itoa(int n)
{
	char	*num_str;
	size_t	size;
	long	nbr;

	size = ft_init_size(n);
	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	num_str = (char *)malloc(sizeof(char ) * (size + 1));
	if (!num_str)
		return (0);
	num_str[size--] = '\0';
	while (nbr > 0)
	{
		num_str[size--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ft_get_first_char(num_str, size));
}
