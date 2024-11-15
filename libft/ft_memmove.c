/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:41:12 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/26 11:21:37 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
* The  memmove() function copies n bytes from memory area src to memory area
* dest. The memory areas may overlap: copying takes place as though the bytes
* in src are first copied into a temporary array that does not overlap src or
* dest, and the bytes are then copied from the temporary array to dest.
* RETURN VALUE:
* The memmove() function returns a pointer to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;

	if (!dest && !src)
		return (NULL);
	ptr_dest = dest;
	ptr_src = src;
	if (ptr_dest > ptr_src)
	{
		ptr_dest = ptr_dest + n - 1;
		ptr_src = ptr_src + n - 1;
		while (n-- > 0)
			*ptr_dest-- = *ptr_src--;
		return (dest);
	}
	else
	{
		while (n-- > 0)
		{
			*ptr_dest++ = *ptr_src++;
		}
		return (dest);
	}
}
