#include "../../includes/cub3d_bonus.h"

const float	hitbox = 0.05;
const float	hitbox_s = 0.1;

int	handle_door(char **map, int x, int y)
{
	int	i = -2;
	int	j;

	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			if (map[y + j][x + i] == 'D')
			{
				map[y + j][x + i] = 'O';
				return (SUCCESS);
			}
			if (map[y + j][x + i] == 'O')
			{
				map[y + j][x + i] = 'D';
				return (SUCCESS);
			}
		}
	}
	return (FAILURE);
}

void	update_straight(t_game *g, int dir)
{
	float	hit;

	hit = 1;
	if (g->dir_x < 0)
		hit *= -1;
	if (g->map[(int)(g->pos_y + hitbox)]
		[(int)(g->pos_x + g->dir_x * MOVE_SPEED + hit * hitbox_s)] != '1'
		&& g->map[(int)(g->pos_y - hitbox)]
		[(int)(g->pos_x + g->dir_x * MOVE_SPEED + hit * hitbox_s)] != '1')
		g->pos_x += g->dir_x * MOVE_SPEED;
	hit = 1;
	if (g->dir_y < 0)
		hit *= -1;
	if (g->map[(int)(g->pos_y + g->dir_y * MOVE_SPEED + hit * hitbox_s)]
		[(int)(g->pos_x + hitbox)] != '1'
		&& (g->map
		[(int)(g->pos_y + g->dir_y * MOVE_SPEED + hit * hitbox_s)]
		[(int)(g->pos_x - hitbox)] != '1'))
		g->pos_y += g->dir_y * MOVE_SPEED;
}
