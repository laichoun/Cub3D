/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:38 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 17:06:37 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <math.h>

void	set_steps_dist(t_game *game)
{
	if (game->dir_ray_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->ray_pos_x) * game->delta_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->ray_pos_x + 1.0 - game->pos_x)
			* game->delta_x;
	}
	if (game->dir_ray_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->ray_pos_y) * game->delta_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->ray_pos_y + 1.0 - game->pos_y)
			* game->delta_y;
	}
}

void	init_render_values(t_game *game, int x)
{
	game->ratio = 2 * x / (float)WIDTH - 1;
	game->dir_ray_x = game->dir_x + game->ratio * game->dir_plane_x;
	game->dir_ray_y = game->dir_y + game->ratio * game->dir_plane_y;
	game->ray_pos_x = game->pos_x;
	game->ray_pos_y = game->pos_y;
	game->delta_x = 1e20;
	if (game->dir_ray_x != 0)
		game->delta_x = fabs(1 / game->dir_ray_x);
	game->delta_y = 1e20;
	if (game->dir_ray_y != 0)
		game->delta_y = fabs(1 / game->dir_ray_y);
	set_steps_dist(game);
}

void	compute_rays(t_game *game)
{
	if (game->side_dist_x < game->side_dist_y)
	{
		game->side_dist_x += game->delta_x;
		game->ray_pos_x += game->step_x;
		game->side = 0;
	}
	else
	{
		game->side_dist_y += game->delta_y;
		game->ray_pos_y += game->step_y;
		game->side = 1;
	}
}

int	set_hit(t_game *game)
{
	if (game->map[game->ray_pos_y][game->ray_pos_x] == '1')
		return (1);
	if (game->map[game->ray_pos_y][game->ray_pos_x] == 'D')
		return (2);
	return (0);
}

void	draw_torch(t_game *g)
{
	int	x = -1;
	int	y = -1;
	//static int	counter = 0;
	int	offx = 1300;//WIDTH - WIDTH / 3;
	int	offy = 500;//HEIGHT - HEIGHT / 3;
	int	*data = (int *)mlx_get_data_addr(g->screen, &g->bpp, &g->size_line, &g->endian);
	int	*t = (int *)mlx_get_data_addr(g->torch, &g->tex_bpp, &g->tex_size_line, &g->tex_endian);
	int	w = g->torch->width;
	int	h = g->torch->height;
	int	color = 0;
	while (++x < w)
	{
		y = -1;
		while (++y < h)
		{
			color = t[y * g->torch->width + x];
			if (color == 0x00000000)
				continue ;
			data[((y + (int)g->t_coefy) + offy) * g->size_line / 4 + ((int)(x + g->t_coefx) + offx)] = color;
		}
	}
}

int	render(t_game *game)
{
	int	x;
	int	hit;

	x = -1;
	while (++x < WIDTH)
	{
		init_render_values(game, x);
		hit = 0;
		while (hit == 0)
		{
			compute_rays(game);
			hit = set_hit(game);
		}
		if (game->side == 0)
			game->dist_perp = (game->side_dist_x - game->delta_x);
		else
			game->dist_perp = (game->side_dist_y - game->delta_y);
		draw_vertline(game, x, hit);
	}
	draw_torch(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (SUCCESS);
}
