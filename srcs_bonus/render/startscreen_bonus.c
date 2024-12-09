/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startscreen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:11:45 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/09 16:45:33 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_startscreen(t_game *game, int frame);
void	draw_scaled_texture(t_game *g, int scale_x, int scale_y, int i);

void	render_startscreen(t_game *game)
{
	static int	frame = 0;
	static int	anim_speed = 600;
	static int	frame_count = 0;

	++frame_count;
	if (frame_count >= anim_speed)
	{
		frame = (frame + 1) % 2;
		frame_count = 0;
	}
	draw_startscreen(game, frame);
}

void	draw_startscreen(t_game *game, int frame)
{
	if (frame == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->start[0], 0, 0);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->start[1], 0, 0);
}
/*
void	draw_scaled_texture(t_game *g, int scale_x, int scale_y, int i)
{
	int	x;
	int	y;
	int	*data;
	int	*src;
	(void) scale_x;
	(void) scale_y;

	data = (int *)mlx_get_data_addr(g->screen, &g->bpp, &g->size_line,
				&g->endian);
	src = (int *)mlx_get_data_addr(g->start[i], &g->tex_bpp,
			&g->tex_size_line, &g->tex_endian);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			int	sx = (int)(x / scale_x);
			int	sy = (int)(y / scale_y);
			data[y * g->screen->width + x] = src[sy * g->start[i]->width + sx];
			//data[y * g->screen->width + x] = 0x0000FF;
		}
	}
}*/
