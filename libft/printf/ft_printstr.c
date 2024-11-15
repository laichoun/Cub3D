/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:31:04 by pibernar          #+#    #+#             */
/*   Updated: 2024/03/05 14:47:13 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_printstr(int fd, char *str)
{
	int		str_len;

	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	str_len = (int)ft_strlen(str);
	ft_putstr_fd(str, fd);
	return (str_len);
}
