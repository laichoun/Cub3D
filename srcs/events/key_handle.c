# include "../../includes/cub3d.h"

int	key_handle(int key, t_game *game)
{
	if (key == XK_Escape)
		free_game(game);
	return (SUCCESS);
}
