/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:08 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/10 16:04:16 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	looping_youhouuuuuuuuuuuuuuu(t_game *game);
static void	init_bonus_textures(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (err_msg(ERROR_WRONG_NBR_ARG, NULL), FAILURE);
	if (init_game(&game, argv[1]))
		return (FAILURE);
	game.t_coefx = 0.0;
	game.t_coefy = 0.0;
	init_bonus_textures(&game);
	looping_youhouuuuuuuuuuuuuuu(&game);
	free_game(&game);
	return (0);
}

static void	looping_youhouuuuuuuuuuuuuuu(t_game *game)
{
	mlx_loop_hook(game->mlx, render, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &key_handle, game);
	mlx_hook(game->win, MotionNotify, PointerMotionMask, &mouse_handle, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_window,
		game);
	mlx_loop(game->mlx);
}

static void	init_texture(void *mlx, t_img **img, char *name)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	*img = mlx_xpm_file_to_image(mlx, name, &w, &h);
}

static void	init_bonus_textures(t_game *g)
{
	init_texture(g->mlx, &g->start[0], "textures/startscreen/gopher2.xpm");
	init_texture(g->mlx, &g->start[1], "textures/startscreen/gopher2.xpm");
	init_texture(g->mlx, &g->door, "textures/castle/door.xpm");
	if (WIDTH < 1920 || HEIGHT < 1080)
	{
		init_texture(g->mlx, &g->torch[0], "textures/torch/atorch1.xpm");
		init_texture(g->mlx, &g->torch[1], "textures/torch/atorch2.xpm");
		init_texture(g->mlx, &g->torch[2], "textures/torch/atorch3.xpm");
	}
	else
	{
		init_texture(g->mlx, &g->torch[0], "textures/torch/abtorch1.xpm");
		init_texture(g->mlx, &g->torch[1], "textures/torch/abtorch2.xpm");
		init_texture(g->mlx, &g->torch[2], "textures/torch/abtorch3.xpm");
	}
}
