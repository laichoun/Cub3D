#include "../../includes/cub3d_bonus.h"

int	select_color(t_game *game, int x, int y);

int	draw_minimap(t_game *game)
{
	int	color;
	int	*mini;
	int	x;
	int	y;

	y = -1;
	mini = (int *)mlx_get_data_addr(game->screen, &game->minimap.mini_bpp,
			&game->minimap.mini_size_line, &game->minimap.mini_endian);
	while (++y < MINI_HEIGHT)
	{
		x = -1;
		while (++x < MINI_WIDTH)
		{
			color = select_color(game, x, y);
			if (color < 0)
				continue ;
			if (color != 0x0094f920)
				mini[y * game->minimap.mini_size_line / 4 + x] = color;
		}
	}
	return (SUCCESS);
}

int	select_color(t_game *game, int x, int y)
{
	int		color;
	int		px;
	float	pos_x;
	float	pos_y;

	px = 3;
	pos_x = 10 * ((float)x * 2 / MINI_WIDTH - 1) + game->pos_x;
	pos_y = 10 * ((float)y * 2 / MINI_HEIGHT - 1) + game->pos_y;
	if (pos_x >= game->col || pos_y >= game->row || pos_x < 0 || pos_y < 0)
		return (-1);
	if (x <= MINI_WIDTH / 2 + px && x >= MINI_WIDTH / 2 - px && y <= MINI_HEIGHT
		/ 2 + px && y >= MINI_HEIGHT / 2 - px)
		color = 0x00FF0000;
	else if (game->map[(int)pos_y][(int)pos_x] == '1')
		color = 0x008C9197;
	else if (game->map[(int)pos_y][(int)pos_x] == '0'
		|| game->map[(int)pos_y][(int)pos_x] == 'E'
		|| game->map[(int)pos_y][(int)pos_x] == 'W'
		|| game->map[(int)pos_y][(int)pos_x] == 'N'
		|| game->map[(int)pos_y][(int)pos_x] == 'S')
		color = 0x00000000;
	else
		color = 0x0094f920;
	return (color);
}
