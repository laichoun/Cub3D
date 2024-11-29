#include "../../includes/cub3d.h"

void	w_key(t_game *game)
{
	float	hitbox;
	float	hitbox_x;
	float	hitbox_y;

	hitbox = 0.1;
	hitbox_x = 0.1;
	hitbox_y = 0.1;
	if (game->dir_x < 0)
		hitbox_x *= -1;
	if (game->dir_y < 0)
		hitbox_y *= -1;
	if (game->map[(int)(game->pos_y + hitbox)]
		[(int)(game->pos_x + game->dir_x * MOVE_SPEED + hitbox_x)] != '1'
		&& game->map[(int)(game->pos_y - hitbox)]
		[(int)(game->pos_x + game->dir_x * MOVE_SPEED + hitbox_x)] != '1')
		game->pos_x += game->dir_x * MOVE_SPEED;
	if (game->map[(int)(game->pos_y + game->dir_y * MOVE_SPEED + hitbox_y)]
		[(int)(game->pos_x + hitbox)] != '1'
		&& (game->map
		[(int)(game->pos_y + game->dir_y * MOVE_SPEED + hitbox_y)]
		[(int)(game->pos_x - hitbox)] != '1'))
		game->pos_y += game->dir_y * MOVE_SPEED;
}

void	a_key(t_game *game)
{
	float	hitbox;
	float	hitbox_x;
	float	hitbox_y;
	float	new_dir_x;
	float	new_dir_y;

	hitbox = 0.1;
	hitbox_x = 0.1;
	hitbox_y = 0.1;
	new_dir_x = game->dir_x * cos(M_PI_2) - game->dir_y * sin(M_PI_2);
	new_dir_y = game->dir_x * sin(M_PI_2) + game->dir_y * cos(M_PI_2);
	if (new_dir_x < 0)
		hitbox_x *= -1;
	if (new_dir_y < 0)
		hitbox_y *= -1;
	if (game->map[(int)(game->pos_y + hitbox)]
		[(int)(game->pos_x + new_dir_x * MOVE_SPEED / 2+ hitbox_x)] != '1'
		&& game->map[(int)(game->pos_y - hitbox)]
		[(int)(game->pos_x + new_dir_x  * MOVE_SPEED / 2 + hitbox_x)] != '1')
		game->pos_x += new_dir_x * MOVE_SPEED / 2;
	if (game->map[(int)(game->pos_y + new_dir_y * MOVE_SPEED / 2 + hitbox_y)]
		[(int)(game->pos_x + hitbox)] != '1'
		&& (game->map
		[(int)(game->pos_y + new_dir_y * MOVE_SPEED / 2 + hitbox_y)]
		[(int)(game->pos_x - hitbox)] != '1'))
		game->pos_y += new_dir_y * MOVE_SPEED / 2;
}

void	s_key(t_game *game)
{
	float	hitbox;
	float	hitbox_x;
	float	hitbox_y;

	hitbox = 0.1;
	hitbox_x = 0.1;
	hitbox_y = 0.1;
	if (game->dir_x < 0)
		hitbox_x *= -1;
	if (game->dir_y < 0)
		hitbox_y *= -1;
	if (game->map[(int)(game->pos_y + hitbox)]
		[(int)(game->pos_x - game->dir_x * MOVE_SPEED - hitbox_x)] != '1'
		&& game->map[(int)(game->pos_y - hitbox)]
		[(int)(game->pos_x - game->dir_x * MOVE_SPEED - hitbox_x)] != '1')
		game->pos_x -= game->dir_x * MOVE_SPEED;
	if (game->map[(int)(game->pos_y - game->dir_y * MOVE_SPEED - hitbox_y)]
		[(int)(game->pos_x + hitbox)] != '1'
		&& (game->map
		[(int)(game->pos_y - game->dir_y * MOVE_SPEED - hitbox_y)]
		[(int)(game->pos_x - hitbox)] != '1'))
		game->pos_y -= game->dir_y * MOVE_SPEED;
}

void	d_key(t_game *game)
{
	float	hitbox;
	float	hitbox_x;
	float	hitbox_y;
	float	new_dir_x;
	float	new_dir_y;

	hitbox = 0.1;
	hitbox_x = 0.1;
	hitbox_y = 0.1;
	new_dir_x = game->dir_x * cos(-M_PI_2) - game->dir_y * sin(-M_PI_2);
	new_dir_y = game->dir_x * sin(-M_PI_2) + game->dir_y * cos(-M_PI_2);
	if (new_dir_x < 0)
		hitbox_x *= -1;
	if (new_dir_y < 0)
		hitbox_y *= -1;
	if (game->map[(int)(game->pos_y + hitbox)]
		[(int)(game->pos_x + new_dir_x * MOVE_SPEED / 2 + hitbox_x)] != '1'
		&& game->map[(int)(game->pos_y - hitbox)]
		[(int)(game->pos_x + new_dir_x  * MOVE_SPEED / 2 + hitbox_x)] != '1')
		game->pos_x += new_dir_x * MOVE_SPEED / 2;
	if (game->map[(int)(game->pos_y + new_dir_y * MOVE_SPEED / 2 + hitbox_y)]
		[(int)(game->pos_x + hitbox)] != '1'
		&& (game->map
		[(int)(game->pos_y + new_dir_y * MOVE_SPEED / 2 + hitbox_y)]
		[(int)(game->pos_x - hitbox)] != '1'))
		game->pos_y += new_dir_y * MOVE_SPEED / 2;
}

