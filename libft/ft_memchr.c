/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:30:30 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/22 14:52:56 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * The  memchr()  function scans the initial n bytes of the memory area pointed
 * to by s for the first instance of c. Both c and the bytes of the memory area 
 * pointed to by s are interpreted as unsigned char.
 * RETURN: return a pointer to the matching byte or NULL if the character 
 * does not occur in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		charac;

	str = (const unsigned char *) s;
	charac = (unsigned char)c;
	while (n-- > 0)
	{
		if (*str == charac)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
