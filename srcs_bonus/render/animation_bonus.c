/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:07:28 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 17:24:08 by pibernar         ###   ########.fr       */
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
	int	*d;
	int	*t;
	int	color;

	d = (int *)g->screen->data;
	t = (int *)g->torch[frame]->data;
	x = -1;
	while (++x < g->torch[frame]->width)
	{
		y = -1;
		while (++y < g->torch[frame]->height)
		{
			if ((int)(x + g->t_coefx) >= g->screen->width ||
			((int)(y + g->t_coefy + 30)) >= g->screen->height)
				continue ;
			color = t[y * g->torch[frame]->width + x];
			if (color == 0x00000000)
				continue ;
			d[(int)(y + g->t_coefy + 30) * g->screen->width
				+(int)(x + g->t_coefx)] = color;
		}
	}
}
