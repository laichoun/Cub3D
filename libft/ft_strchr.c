/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:15:56 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/22 15:16:01 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
* The strchr() function returns a pointer to the first occurrence of the
* character c in the string s.
* RETURN:
* 
* return a pointer to the matched character or NULL if the character is not 
* found. The terminating null byte is considered part of the string, so that
* if c is specified as '\0', these functions return a pointer to the terminator
*/
char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	i;

	ch = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)&s[i]);
	return (0);
}
