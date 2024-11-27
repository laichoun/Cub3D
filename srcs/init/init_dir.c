#include "../../includes/cub3d.h"

static void	set_dir(t_game *gamep, int dir_x, int dir_y)
{
	gamep->dir[0] = dir_x;
	gamep->dir[1] = dir_y;
	gamep->dir_p[0] = 0.66 * (dir_x * cos(-M_PI_2) - dir_y * sin(-M_PI_2));
	gamep->dir_p[1] = 0.66 * (dir_x * sin(-M_PI_2) + dir_y * cos(-M_PI_2));
}

int	set_player_dir(t_game *gamep, t_file *file)
{
	if (file->dir == 'N')
		set_dir(gamep, 0, -1);
	else if (file->dir == 'S')
		set_dir(gamep, 0, 1);
	else if (file->dir == 'E')
		set_dir(gamep, 1, 0);
	else if (file->dir == 'W')
		set_dir(gamep, -1, 0);
	return (SUCCESS);
}
