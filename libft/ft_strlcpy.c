/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:24:43 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/23 11:10:10 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

/*
 * The strlcpy() function copies strings. They are designed to be safer, 
 * more consistent, and less error prone replacements for strncat(3). Unlike
 * this function, strlcpy() take the full size of the buffer (not just
 * the length) and guarantee to NUL-terminate the result (as long as size is
 * larger than 0.
 * Note that a byte for the NUL should be included in size.  Also note that 
 * strlcpy() only operates on true “C” strings. This means that src must be 
 * NUL-terminated
 * The strlcpy() function copies up to size - 1 characters from the 
 * NUL-terminated string src to dst, NUL-terminating the result.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
