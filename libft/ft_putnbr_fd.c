/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:54:35 by pibernar          #+#    #+#             */
/*   Updated: 2024/02/23 13:55:31 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar_fd(char c, int fd);

/*
 * Outputs the integer ’n’ to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (fd < 0)
		return ;
	if (n < 0)
	{
		sign *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10 * sign, fd);
	ft_putchar_fd('0' + n % 10 * sign, fd);
}
