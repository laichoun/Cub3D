#include "../../includes/cub3d.h"

/*
static void	mlx_draw_vertline(int x, int drawStart, int drawEnd, int color,
		t_game *game)
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
*/



void	set_cur_texture(t_game *game)
{
	if (game->side == 0)
	{
		if (game->dir_ray_x > 0)
			game->cur_tex = game->textures.img_ea;
		else
			game->cur_tex = game->textures.img_we;
	}
	else
	{
		if (game->dir_ray_y < 0)
			game->cur_tex = game->textures.img_so;
		else
			game->cur_tex = game->textures.img_no;
	}
}

static void	mlx_draw_vertline_texutre(int x, int drawStart, int drawEnd,
		t_game *game)
{
	int		*dst;
	int		bpp;
	int		size_line;
	int		endian;
	int		y;
	int		*texture_data;
	int		texture_bpp;
	int		texture_size_line;
	int		texture_endian;
	int		color;


	dst = (int *)mlx_get_data_addr(game->screen, &bpp, &size_line, &endian);
	texture_data = (int *)mlx_get_data_addr(game->cur_tex, &texture_bpp,
			&texture_size_line, &texture_endian);
	// How much to increase the texture coordinate per screen pixel
	//  game->tex_step = 1.0 * TEXT_WIDTH / line_height;
	// Starting texture coordinate
	//  game->tex_y = (drawStart - HEIGHT / 2 + line_height / 2)
	//	* game->tex_step;
	y = 0;
	while (y <= HEIGHT)
	{
		if (y < drawStart)
			dst[y * size_line / 4 + x] = game->textures.c_rgb;
		else if (drawStart <= y && y <= drawEnd)
		{
			// Calculer la coordonnée y de la texture
			game->tex_y = (int)game->tex_pos & (game->cur_tex->height - 1);
			game->tex_pos += game->tex_step;
			// Obtenir la couleur du pixel de texture
			color = texture_data[(int)game->tex_y * game->cur_tex->width + game->tex_x];
			// Assombrir légèrement si c'est un mur sur le côté secondaire
				//if (game->side == 1)
				//	color = (color >> 1) & 0x7F7F7F;
			// Dessiner le pixel
			dst[y * size_line / 4 + x] = color;
		}
		else
			dst[y * size_line / 4 + x] = game->textures.f_rgb;
		++y;
	}
}

void	draw_vertline(t_game *game, int x)
{
	int	line_height;
	int	start;
	int	end;

	// int	color;
	// t_img	*texture;
	line_height = (int)(HEIGHT / game->dist_perp);
	start = -line_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	// calculate the position where the wall was hit
	// East or West else North or South
	if (game->side == 0)
		game->hit_wall = game->pos_y + game->dist_perp * game->dir_ray_y;
	else
		game->hit_wall = game->pos_x + game->dist_perp * game->dir_ray_x;
	// to find the exact position according to the width of the wall
	game->hit_wall -= floor(game->hit_wall);
	
	
	set_cur_texture(game);
	
	
	// find the x coordinate on the texture
	game->tex_x = (int)(game->hit_wall * game->cur_tex->width);
	// managements inversions / reflexions
	if (game->side == 0 && game->dir_ray_x > 0)
		game->tex_x = game->cur_tex->width - game->tex_x - 1;
	if (game->side == 1 && game->dir_ray_y < 0)
		game->tex_x = game->cur_tex->width - game->tex_x - 1;
	// How much to increase the texture coordinate per screen pixel
	game->tex_step = game->cur_tex->width / line_height;
	// Starting texture coordinate
	game->tex_pos = (start - HEIGHT / 2 + line_height / 2) * game->tex_step;
	mlx_draw_vertline_texutre(x, start, end, game);
}
