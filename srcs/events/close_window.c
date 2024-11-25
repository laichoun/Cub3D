#include "../../includes/cub3d.h"

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (SUCCESS);
}
