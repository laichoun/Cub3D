/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:08 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/18 17:19:36 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	looping_youhouuuuuuuuuuuuuuu(t_game *game);
static void	init_bonus_textures(t_game *game);
void		init_blank_game(t_game *gamep);

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

int	launch_game(t_game *game)
{
	init_blank_game(game);
	init_window(game);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	(void) argv;
	if (argc != 1)
		return (err_msg(ERROR_WRONG_NBR_ARG, NULL), FAILURE);
	if (launch_game(&game) == FAILURE)
		return (err_msg(100, "send help"), FAILURE);
	init_bonus_textures(&game);
	looping_youhouuuuuuuuuuuuuuu(&game);
	free_game(&game);
	free_window(&game);
	return (0);
}

static void	looping_youhouuuuuuuuuuuuuuu(t_game *game)
{
	mlx_loop_hook(game->mlx, render, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &keypress_handle, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &keyrelease_handle, game);
	mlx_hook(game->win, MotionNotify, PointerMotionMask, &mouse_handle, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_window,
		game);
	mlx_loop(game->mlx);
}

static void	init_xpm(void *mlx, t_img **img, char *name)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	*img = mlx_xpm_file_to_image(mlx, name, &w, &h);
}

static void	init_bonus_textures(t_game *g)
{
	init_xpm(g->mlx, &g->start[0], "textures/menu/startscreen.xpm");
	init_xpm(g->mlx, &g->start[1], "textures/menu/startscreen.xpm");
	init_xpm(g->mlx, &g->start[2], "textures/menu/mapselectionplaceholder.xpm");
	init_xpm(g->mlx, &g->door[0], "textures/castle/door_v.xpm");
	init_xpm(g->mlx, &g->door[1], "textures/castle/secret.xpm");
	init_xpm(g->mlx, &g->door[2], "textures/castle/door_v.xpm");
	init_xpm(g->mlx, &g->torch[0], "textures/torch/torch1.xpm");
	init_xpm(g->mlx, &g->torch[1], "textures/torch/torch2.xpm");
	init_xpm(g->mlx, &g->torch[2], "textures/torch/torch3.xpm");
}
