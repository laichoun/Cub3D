/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:38 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/23 15:40:43 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <X11/X.h>
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
	char	tile;

	tile = game->map[game->ray_pos_y][game->ray_pos_x];
	if (tile == '1')
		return (1);
	if (tile == 'D' || tile == 'T')
		return (2);
	if (tile == 'L')
		return (3);
	if (tile == 'B')
		return (4);
	return (0);
}

int	render_raycast(t_game *game)
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
			game->dist_perp = game->side_dist_x - game->delta_x;
		else
			game->dist_perp = game->side_dist_y - game->delta_y;
		draw_vertline(game, x, hit);
	}
	return (Success);
}
