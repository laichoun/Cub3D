/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:20:50 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/23 17:42:02 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int		select_color(t_game *game, int x, int y);

int	draw_minimap(t_game *game)
{
	int	color;
	int	*mini;
	int	x;
	int	y;

	y = -1;
	mini = (int *)game->screen->data;
	while (++y < MINI_HEIGHT)
	{
		x = -1;
		while (++x < MINI_WIDTH)
		{
			color = select_color(game, x, y);
			if (color < 0)
				continue ;
			if (color != 0x0094f920)
				mini[y * game->screen->width + x] = color;
		}
	}
	return (SUCCESS);
}

int	select_color(t_game *game, int x, int y)
{
	int		px;
	float	pos_x;
	float	pos_y;
	char	t;

	px = 3;
	pos_x = 10 * (x * 2.0 / MINI_WIDTH - 1) + game->pos_x;
	pos_y = 10 * (y * 2.0 / MINI_HEIGHT - 1) + game->pos_y;
	if (pos_x >= game->col || pos_y >= game->row || pos_x < 0 || pos_y < 0)
		return (-1);
	t = game->map[(int)pos_y][(int)pos_x];
	if (x <= MINI_WIDTH / 2 + px && x >= MINI_WIDTH / 2 - px && y <= MINI_HEIGHT
		* 0.5 + px && y >= MINI_HEIGHT * 0.5 - px)
		return (0x00FF0000);
	else if (t == '1' || t == 'L')
		return (0x008C9197);
	else if (t == '0' || t == 'E' || t == 'W' || t == 'N' || t == 'S')
		return (0x00000000);
	else if (t == 'D' || t == 'T' || t == 'B')
		return (0x00965d4c);
	else if (t == 'O')
		return (0x00ffdb99);
	else
		return (0x0094f920);
}
