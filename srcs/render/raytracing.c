#include "../../includes/cub3d.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void mlx_draw_vertline(int x, int drawStart, int drawEnd, int color, t_game *game)
{
	int *dst;
	int	bpp;
	int size_line;
	int endian;

	dst = (int *)mlx_get_data_addr(game->screen, &bpp, &size_line, &endian);
	int y = 0;
	while (y <= HEIGHT)
	{
		if (y < drawStart)
			dst[y * size_line / 4 + x] = 0x000000FF;
		else if (drawStart <= y && y <= drawEnd)
			dst[y * size_line / 4 + x] = color;
		else
			dst[y * size_line / 4 + x] = 0x00663300;
		++y;
	}
}

int		render(t_game *game)
{
	float	ratio;

	for (int x = 0; x < WIDTH; ++x)
	{
		ratio = 2 * x / (float)WIDTH - 1;	
		game->dir_ray_x = game->dir_x + game->dir_plane_x * ratio;
		game->dir_ray_y = game->dir_y + game->dir_plane_y * ratio;

		game->ray_pos_x = game->pos_x;
		game->ray_pos_y = game->pos_y;

		game->delta_x = (game->dir_ray_x == 0) ? 1e20 : fabs(1 / game->dir_ray_x);
		game->delta_y = (game->dir_ray_y == 0) ? 1e20 : fabs(1 / game->dir_ray_y);

		int hit = 0;

		if (game->dir_ray_x < 0)
		{
			game->step_x = -1;
			game->side_dist_x = (game->pos_x - game->ray_pos_x) * game->delta_x;
		}
		else
		{
			game->step_x = 1;
			game->side_dist_x = (game->ray_pos_x + 1.0 - game->pos_x) * game->delta_x;
		}
		if (game->dir_ray_y < 0)
		{
			game->step_y = -1;
			game->side_dist_y = (game->pos_y - game->ray_pos_y) * game->delta_y;
		}
		else
		{
			game->step_y = 1;
			game->side_dist_y = (game->ray_pos_y + 1.0 - game->pos_y) * game->delta_y;
		}
		while (hit == 0)
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
			//if (mapX < 0 || mapY < 0 || mapX >= game->row || mapY >= game->col)
			//	break ;
			if (game->map[game->ray_pos_y][game->ray_pos_x] == '1'
				|| game->map[game->ray_pos_y][game->ray_pos_x] == '2')
				hit = 1;
		}
		if (game->side == 0)
			game->dist_perp = (game->side_dist_x - game->delta_x);
		else
			game->dist_perp = (game->side_dist_y - game->delta_y);
		draw_vertline(game, x);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
		return(err_msg(ERROR_WRONG_NBR_ARG, NULL), FAILURE);
	if (init_game(&game, argv[1]))
		return(FAILURE);
/*
=============================================================================
									TESTS
=============================================================================
*/

/*
=============================================================================
=============================================================================
*/
	mlx_loop_hook(game.mlx, render, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &key_handle, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &close_window,
		&game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
