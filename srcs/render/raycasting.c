#include "../../includes/cub3d.h"

int	render(t_game *game)
{
	int		x;
	float	ratio;
	float	ray_x;
	float	ray_y;
	int		map[2];

	x = -1;
	while (++x < WIDTH)
	{
		ratio = 2 * x / (double)WIDTH - 1;
		ray_x = game->dir[0] + ratio * game->dir_p[0];
		ray_y = game->dir[1] + ratio * game->dir_p[1];
		map[0] = game->pos_x;
		map[1] = game->pos_y;
	}
	return (SUCCESS);
}
