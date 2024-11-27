# include "../../includes/cub3d.h"
#include <math.h>

int	key_handle(int key, t_game *game)
{
	double rotspeed = 0.09;
	double movespeed = 0.3;
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	if (key == XK_w)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x + game->dir[0]*movespeed)] == '0')
			game->pos_x += game->dir[0] * movespeed;
		if (game->map[(int)(game->pos_y + game->dir[1]*movespeed)][(int)(game->pos_x)] == '0')
			game->pos_y += game->dir[1] * movespeed;
	}
	if (key == XK_s)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x - game->dir[0]*movespeed)] == 0)
			game->pos_x -= game->dir[0] * movespeed;
		if (game->map[(int)(game->pos_y - game->dir[1]*movespeed)][(int)(game->pos_x)] == 0)
			game->pos_y -= game->dir[1] * movespeed;
	}
	if (key == XK_a)
		game->pos_y -= 0.1;
	if (key == XK_d)
		game->pos_y += 0.1;
	//droite
	if (key == 65363)
	{
		float oldDirX = game->dir[0];
		game->dir[0] = game->dir[0] * cos(-rotspeed) - game->dir[1] * sin(-rotspeed);
		game->dir[1] = oldDirX * sin(-rotspeed) + game->dir[1] * cos(-rotspeed);
		float oldPaneX = game->dir_p[0];
		game->dir_p[0] = game->dir_p[0] * cos(-rotspeed) - game->dir_p[1] * sin(-rotspeed);
		game->dir_p[1] = oldPaneX * sin(-rotspeed) + game->dir_p[1] * cos(-rotspeed);
	}
	//gauche
	if (key == 65361)
	{
		float oldDirX = game->dir[0];
		game->dir[0] = game->dir[0] * cos(rotspeed) - game->dir[1] * sin(rotspeed);
		game->dir[1] = oldDirX * sin(rotspeed) + game->dir[1] * cos(rotspeed);
		float oldPaneX = game->dir_p[0];
		game->dir_p[0] = game->dir_p[0] * cos(rotspeed) - game->dir_p[1] * sin(rotspeed);
		game->dir_p[1] = oldPaneX * sin(rotspeed) + game->dir_p[1] * cos(rotspeed);
	}
	return (SUCCESS);
}
