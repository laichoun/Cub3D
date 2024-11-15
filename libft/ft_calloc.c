/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:29:04 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/23 16:29:15 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n);

/*
 * The  calloc() function allocates memory for an array of nmemb elements of 
 * size bytes each and returns a pointer to the allocated memory. The memory 
 * is set to zero. If nmemb or size is 0, then calloc() returns either NULL, 
 * or a unique pointer value that can later be successfully passed to free(). 
 * If the multiplication of nmemb and size would result in integer overflow,
 * then calloc() returns an error.  By contrast, an integer overflow would not
 * be detected in the following call to malloc(), with the result that an
 * incorrectly sized block of memory would be allocated: 
 * malloc(nmemb * size);
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = (void *)malloc(0);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (nmemb > UINT_MAX / size)
		return (NULL);
	ptr = (void *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
