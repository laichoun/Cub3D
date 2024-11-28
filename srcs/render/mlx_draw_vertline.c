#include "../../includes/cub3d.h"

static void mlx_draw_vertline(int x, int drawStart, int drawEnd, int color, t_game *game)
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

void	draw_vertline(t_game *game, int x)
{
	int	color;
	int	line_height;
	int	start;
	int	end;

	line_height = (int) (HEIGHT / game->dist_perp);
	start = -line_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	color = 0x00000000;
	if (game->map[game->ray_pos_y][game->ray_pos_x] == '1')
		color = 0x00FF0000; 
	else if (game->map[game->ray_pos_y][game->ray_pos_x] == '2')
		color = 0x0000FF00; 
	if (game->side == 1)
		color /= 2;
	mlx_draw_vertline(x, start, end, color, game);
}
