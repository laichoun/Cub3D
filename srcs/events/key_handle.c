# include "../../includes/cub3d.h"

int	key_handle(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	if (key == XK_w)
		game->pos_x -= 0.3;
	if (key == XK_s)
		game->pos_x += 0.3;
	if (key == XK_a)
		game->pos_y -= 0.1;
	if (key == XK_d)
		game->pos_y += 0.1;
	return (SUCCESS);
}
