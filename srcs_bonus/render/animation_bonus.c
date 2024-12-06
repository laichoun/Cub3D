/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:07:28 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/06 10:16:24 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_torch(t_game *g, int frame);

void	render_animation(t_game *game)
{
	static int	frame = 0;
	static int	anim_speed = 5;
	static int	frame_count = 0;

	++frame_count;
	if (frame_count >= anim_speed)
	{
		frame = (frame + 1) % 3;
		frame_count = 0;
	}
	draw_torch(game, frame);
}

void	draw_torch(t_game *g, int frame)
{
	int	x;
	int	y;
	int	offx = WIDTH - WIDTH / 3;//1100;
	int	offy = HEIGHT - HEIGHT / 2;//500;
	int	*data = (int *)mlx_get_data_addr(g->screen, &g->bpp, &g->size_line, &g->endian);
	int	*t = (int *)mlx_get_data_addr(g->torch[frame], &g->tex_bpp, &g->tex_size_line, &g->tex_endian);
	int	w = g->torch[frame]->width;
	int	h = g->torch[frame]->height;
	int	color = 0;

	x = -1;
	while (++x < w)
	{
		y = -1;
		while (++y < h)
		{
			color = t[y * g->torch[frame]->width + x];
			if (color == 0x00000000)
				continue ;
			data[(int)(y + g->t_coefy + offy) * g->size_line / 4 + (int)(x + g->t_coefx + offx)] = color;
		}
	}
}
