#include "../../includes/cub3d.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*int		ft_texture(t_game *game, int x, int y)
{
	int *dst;
	int	bpp;
	int size_line;
	int endian;

	dst = (int *)mlx_get_data_addr(game->textures.img_no, &bpp, &size_line, &endian);

	return 0;
}*/

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
	for (int x = 0; x < WIDTH; ++x)
	{
		double cameraX = 2 * x / (double)WIDTH - 1;	
		float rayDirX = game->dir[0] + game->dir_p[0] * cameraX;
		float rayDirY = game->dir[1] + game->dir_p[1] * cameraX;

		int mapX = game->pos_x;
		int mapY = game->pos_y;

		float sideDistX;
		float sideDistY;

		float deltaDistX = (rayDirX == 0) ? 1e20 : fabs(1 / rayDirX);
		float deltaDistY = (rayDirY == 0) ? 1e20 : fabs(1 / rayDirY);

		float perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = ( mapX + 1.0 - game->pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = ( mapY + 1.0 - game->pos_y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (mapX < 0 || mapY < 0 || mapX >= game->row || mapY >= game->col)
				break ;
			if (game->map[mapY][mapX] == '1' || game->map[mapY][mapX] == '2')
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		int lineHeight = (int) (HEIGHT / perpWallDist);
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		int color;
		if (hit == 0)
		{
			mlx_draw_vertline(x, 0, HEIGHT, 0x00000000, game);
			continue;
		}
		switch (game->map[mapY][mapX])
		{
			case '2': color = 0x0000FF00; break;
			case '1': color = 0x00FF0000; break;
		}
		if (side == 1) color /= 2;
		mlx_draw_vertline(x, drawStart, drawEnd, color, game);
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
