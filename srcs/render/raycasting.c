#include "../../includes/cub3d.h"

void	init_render_values(t_game *game, int x)
{
		game->ratio = 2 * x / (double)WIDTH - 1;
		game->dir_ray_x = game->dir_x + game->ratio * game->dir_plane_x;
		game->dir_ray_y = game->dir_y + game->ratio * game->dir_plane_y;

}

int	render(t_game *game)
{
	int		x;
	int		map[2];

	x = -1;
	while (++x < WIDTH)
	{
		init_render_values(game, x);
		map[0] = game->pos_x;
		map[1] = game->pos_y;
	}
	return (SUCCESS);
}
