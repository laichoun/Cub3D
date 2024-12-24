/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:01:33 by laichoun          #+#    #+#             */
/*   Updated: 2024/12/23 15:31:30 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_xpm(void *mlx, t_img **img, char *name)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	*img = mlx_xpm_file_to_image(mlx, name, &w, &h);
}

void	init_bonus_textures(t_game *g)
{
	init_xpm(g->mlx, &g->start[0], "textures/menu/start_menu.xpm");
	init_xpm(g->mlx, &g->start[1], "textures/menu/start_menu_start.xpm");
	init_xpm(g->mlx, &g->start[2], "textures/menu/start_menu_levels.xpm");
	init_xpm(g->mlx, &g->start[3], "textures/menu/start_menu_credits.xpm");
	init_xpm(g->mlx, &g->start[4], "textures/menu/start_menu_exit.xpm");
	init_xpm(g->mlx, &g->start[5], "textures/menu/map_selection.xpm");
	init_xpm(g->mlx, &g->start[6], "textures/menu/Credits.xpm");
	init_xpm(g->mlx, &g->start[7], "textures/menu/issou.xpm");
	init_xpm(g->mlx, &g->door[0], "textures/castle/door_v.xpm");
	init_xpm(g->mlx, &g->door[1], "textures/castle/stairs.xpm");
	init_xpm(g->mlx, &g->door[2], "textures/castle/door_boss.xpm");
	init_xpm(g->mlx, &g->torch[0], "textures/torch/torch1.xpm");
	init_xpm(g->mlx, &g->torch[1], "textures/torch/torch2.xpm");
	init_xpm(g->mlx, &g->torch[2], "textures/torch/torch3.xpm");
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (err_msg(ERROR_MLX, NULL), FAILURE);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->screen = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->state = 0;
	return (SUCCESS);
}
