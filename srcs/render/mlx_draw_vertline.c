#include "../../includes/cub3d.h"

/*
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
*/

static void mlx_draw_vertline_texutre(int x, int drawStart, int drawEnd, t_game *game)
{
	int	*dst;
	int	bpp;
	int	size_line;
	int	endian;
	int	y;

	int	*texture_data;
	int	texture_bpp;
	int	texture_size_line;
	int	texture_endian;
	t_img	*texture;
	if (game->side == 0)
	{
		if (game->dir_ray_x > 0)
			texture = game->textures.img_ea;
		else 
		texture = game->textures.img_we;
	}
	else
	{
		if (game->dir_ray_y < 0)
			texture = game->textures.img_so;
		else
			texture = game->textures.img_no;
	}
	dst = (int *)mlx_get_data_addr(game->screen, &bpp, &size_line, &endian);
	texture_data = (int *)mlx_get_data_addr(texture, &tex_bpp, &tex_size_line, &tex_endian);
	
    // How much to increase the texture coordinate per screen pixel
    double step = 1.0 * TEXT_WIDTH / line_height;
    // Starting texture coordinate
    double texPos = (drawStart - HEIGHT / 2 + line_height / 2) * step;
	y = 0;
	while (y <= HEIGHT)
	{
		if (y < drawStart)
			dst[y * size_line / 4 + x] = game->textures.c_rgb;
		else if (drawStart <= y && y <= drawEnd)
			//dst[y * size_line / 4 + x] = color;
		{
       	 // Calculer la coordonnée y de la texture
        	int tex_y = (int)tex_pos & (TEXT_HEIGHT - 1);
        	tex_pos += tex_step;

        // Obtenir la couleur du pixel de texture
        	int color = texture_data[tex_y * TEXT_WIDTH + game->tex_x];

        // Assombrir légèrement si c'est un mur sur le côté secondaire
        	if (game->side == 1)
            color = (color >> 1) & 0x7F7F7F;

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
	int	color;
	int	line_height;
	int	start;
	int	end;
	//t_img	*texture;

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
/*
	if (game->side == 0)
	{
		if (game->dir_ray_x > 0)
			texture = game->textures.img_ea;
		else 
		texture = game->textures.img_we;
	}
	else
	{
		if (game->dir_ray_y < 0)
			texture = game->textures.img_so;
		else
			texture = game->textures.img_no;
	}
	*/
	mlx_draw_vertline_texutre(x, start, end, game);
}
