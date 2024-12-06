/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:38 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/06 18:35:52 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <math.h>

int	draw_minimap(t_game *game);

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
			game->dist_perp = game->side_dist_x - game->delta_x;
		else
			game->dist_perp = game->side_dist_y - game->delta_y;
		draw_vertline(game, x, hit);
	}
	draw_minimap(game);
	render_animation(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (SUCCESS);
}
