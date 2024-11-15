/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:40:49 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/23 11:08:32 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);

/*
* The strrchr() function returns a pointer to the last occurrence of the
* character c in the string s.
*/
char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	charac;

	len = ft_strlen(s);
	charac = c;
	while (len >= 0)
	{
		if (s[len] == charac)
			return ((char *)&s[len]);
		len--;
	}
	return (0);
}
