/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:08 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 13:13:08 by pibernar         ###   ########.fr       */
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

static void	init_bonus_textures(t_game *g)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	g->door = NULL;
	g->door = mlx_xpm_file_to_image(g->mlx, "textures/door.xpm", &w, &h);
	g->torch[0] = mlx_xpm_file_to_image(g->mlx, "textures/torch1.xpm", &w, &h);
	g->torch[1] = mlx_xpm_file_to_image(g->mlx, "textures/torch2.xpm", &w, &h);
	g->torch[2] = mlx_xpm_file_to_image(g->mlx, "textures/torch3.xpm", &w, &h);
}
