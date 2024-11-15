/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:52:40 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/22 15:06:29 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
* compares the first n bytes (each interpreted as
*  unsigned char) of the memory areas s1 and s2.
* RETURN VALUE:
* returns an integer less than, equal to, or greater 
* than zero if the first n bytes of s1 is found, respectively, to be less than,
* to match, or be greater than the first n bytes of s2.
* For a nonzero return value, the sign is determined by the sign of the 
* difference between the first pair of bytes (interpreted as unsigned char)
* that differ in s1 and s2.
* If n is zero, the return value is zero.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
