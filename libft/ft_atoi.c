/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:11:01 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/23 12:42:46 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int i);

/*
 * The atoi() function converts the initial portion of the string 
 * pointed to by nptr to int.
*/
int	ft_atoi(const char *nptr)
{
	int		sign;
	int		i;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return ((int)(sign * res));
}
