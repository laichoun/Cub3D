#include "../../includes/cub3d.h"
#include <math.h>
#include <stdio.h>

int	key_handle(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	if (key == XK_w)
		w_key(game);
	if (key == XK_s)
		s_key(game);
	if (key == XK_a)
		game->pos_y -= 0.1;
	if (key == XK_d)
		game->pos_y += 0.1;
	if (key == 65363)
		right_arrow_key(game);
	if (key == 65361)
		left_arrow_key(game);
	return (SUCCESS);
}
