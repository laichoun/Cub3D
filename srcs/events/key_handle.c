# include "../../includes/cub3d.h"

int	key_handle(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	return (SUCCESS);
}
