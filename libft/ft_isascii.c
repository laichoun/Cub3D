/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:19:52 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/20 09:09:21 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* checks whether c is a 7-bit unsigned char value that fits into the ASCII 
* character set.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
