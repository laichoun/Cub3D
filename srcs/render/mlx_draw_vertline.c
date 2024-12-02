#include "../../includes/cub3d.h"

static void mlx_draw_vertline(int x, int drawStart, int drawEnd, int color, t_game *game)
{
	int	*dst;
	int	bpp;
	int	size_line;
	int	endian;
	int	y;

	dst = (int *)mlx_get_data_addr(game->screen, &bpp, &size_line, &endian);
	y = 0;
	while (y <= HEIGHT)
	{
		if (y < drawStart)
			dst[y * size_line / 4 + x] = game->textures.c_rgb;
		else if (drawStart <= y && y <= drawEnd)
			dst[y * size_line / 4 + x] = color;
		else
			dst[y * size_line / 4 + x] = game->textures.f_rgb;

		++y;
	}
}

void	draw_vertline(t_game *game, int x)
{
	int	color;
	int	line_height;
	int	start;
	int	end;
	t_img	*texture[1];

	line_height = (int)(HEIGHT / game->dist_perp);
	start = -line_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	
	//calculate the position where the wall was hit
	// East or West else North or South
	if (game->side == 0)
		game->hit_wall = game->pos_y + game->dist_perp * game->dir_ray_y;
	else
		game->hit_wall = game->pos_x + game->dist_perp * game->dir_ray_x;
	//to find the exact position according to the width of the wall
	game->hit_wall -=floor(game->hit_wall);
	
	//find the x coordinate on the texture
	game->tex_x = (int)(game->hit_wall * (double)TEXT_WIDTH);
	//managements inversions / reflexions
	if (game->side == 0 && game->dir_ray_x > 0)
		game->tex_x = TEXT_WIDTH - game->tex_x - 1;
	if (game->side == 1 && game->dir_ray_y < 0)
		game->tex_x = TEXT_WIDTH - game->tex_x - 1;	
	
	
	if (game->side == 0 && game->dir_ray_x > 0)
		//texture est
		texture[0] = game->textures.img_ea;
	else 
		//texture ouest
		texture[0] = game->textures.img_we;
	if (game->side == 1 && game->dir_ray_y < 0)
		//texture sud
		texture[0] = game->textures.img_so;
	else
		//texture nord
		texture[0] = game->textures.img_no;




	
	color = 0x00000000;
	if (game->map[game->ray_pos_y][game->ray_pos_x] == '1')
		color = 0x008C9197;
	if (game->side == 1)
		color = 0x004D5152;
	
	mlx_draw_vertline(x, start, end, color, game);
}
