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

//TODO:: create isCollision funct
int	is_coll(int x, int y, char **map)
{
	return (map[y][x] == '1' || map[y][x] == 'D');
}
