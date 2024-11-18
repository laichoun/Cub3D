/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:27:31 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/15 15:28:22 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	char str[] = "Hello world, how is it going,,,,,,!!!!!! plop,,,hi";
	char **tab = ft_strtok(str, " ,");
	int i= -1;
	while (tab[++i])
		ft_printf("%s\n", tab[i]);
	ft_free_split(tab);
	return (0);
}
