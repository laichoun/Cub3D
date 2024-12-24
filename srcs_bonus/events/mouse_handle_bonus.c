/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:19 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/20 15:57:21 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	mouse_right(t_game *game);
static void	mouse_left(t_game *game);

int	mouse_selection(int key, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (key == 1 && game->state == 0)
	{
		if (game->menuid == 1)
		{
			free_game(game);
			if (new_map(game, game->level[0]) == FAILURE)
				return (FAILURE);
			game->state = 2;
		}
		else if (game->menuid == 2)
			game->state = 1;
		else if (game->menuid == 3)
			game->state = 4;
		else if (game->menuid == 4)
			mlx_loop_end(game->mlx);
	}
	return (SUCCESS);
}

int	menu_select(int x, int y, t_game *game)
{
	if (x >= 37 && x <= 202 && y >= 238 && y <= 297)
		game->menuid = 1;
	else if (x >= 37 && x <= 247 && y >= 330 && y <= 409)
		game->menuid = 2;
	else if (x >= 37 && x <= 189 && y >= 470 && y <= 519)
		game->menuid = 3;
	else if (x >= 37 && x <= 123 && y >= 595 && y <= 637)
		game->menuid = 4;
	else
		game->menuid = 0;
	return (SUCCESS);
}

int	mouse_handle(int x, int y, t_game *game)
{
	static int	old_mpos = 0;

	(void)x;
	(void)y;
	if (game->state == 0)
	{
		menu_select(x, y, game);
		return (SUCCESS);
	}
	if (old_mpos < x || old_mpos == WIDTH - 1)
		mouse_right(game);
	else if (old_mpos > 0 || old_mpos == 0)
		mouse_left(game);
	old_mpos = x;
	return (SUCCESS);
}

static void	mouse_left(t_game *game)
{
	float		temp_dir_x;
	float		temp_plane_x;
	const float	mouse_rot = 0.015;

	temp_plane_x = game->dir_plane_x;
	temp_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(-mouse_rot) - game->dir_y * sin(-mouse_rot);
	game->dir_y = temp_dir_x * sin(-mouse_rot) + game->dir_y * cos(-mouse_rot);
	game->dir_plane_x = game->dir_plane_x * cos(-mouse_rot) - game->dir_plane_y
		* sin(-mouse_rot);
	game->dir_plane_y = temp_plane_x * sin(-mouse_rot) + game->dir_plane_y
		* cos(-mouse_rot);
}

static void	mouse_right(t_game *game)
{
	float		temp_dir_x;
	float		temp_plane_x;
	const float	mouse_rot = 0.015;

	temp_plane_x = game->dir_plane_x;
	temp_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(mouse_rot) - game->dir_y * sin(mouse_rot);
	game->dir_y = temp_dir_x * sin(mouse_rot) + game->dir_y * cos(mouse_rot);
	game->dir_plane_x = game->dir_plane_x * cos(mouse_rot) - game->dir_plane_y
		* sin(mouse_rot);
	game->dir_plane_y = temp_plane_x * sin(mouse_rot) + game->dir_plane_y
		* cos(mouse_rot);
}
