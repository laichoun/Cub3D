#include "../../includes/cub3d.h"

int	init_raycast(t_game *game, t_file *file)
{
	game->pos_x = (float) file->player_x;
	game->pos_y = (float) file->player_y;
	return (SUCCESS);
}
