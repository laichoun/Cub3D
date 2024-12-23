/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:06:15 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/23 15:36:24 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	handle_door(char **map, int x, int y)
{
	int	i;
	int	j;

	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			if (map[y + j][x + i] == 'D')
			{
				map[y + j][x + i] = 'O';
				return (SUCCESS);
			}
			if (map[y + j][x + i] == 'O')
			{
				map[y + j][x + i] = 'D';
				return (SUCCESS);
			}
		}
	}
	return (FAILURE);
}

int	is_coll(int x, int y, char **map)
{
	return (map[y][x] == '1' || map[y][x] == 'D' || map[y][x] == 'L'
		|| map[y][x] == 'B' || map[y][x] == 'T');
}
