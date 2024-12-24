/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:08 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/20 16:06:47 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	looping_youhouuuuuuuuuuuuuuu(t_game *game);
void	init_bonus_textures(t_game *game);
int	init_window(t_game *game);
void		init_blank_game(t_game *gamep);

int	launch_game(t_game *game)
{
	init_blank_game(game);
	init_window(game);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	(void)argv;
	if (argc != 1)
		return (err_msg(ERROR_WRONG_NBR_ARG, NULL), FAILURE);
	if (launch_game(&game) == FAILURE)
		return (err_msg(100, "send help"), FAILURE);
	init_bonus_textures(&game);
	map_menu(&game);
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
	mlx_hook(game->win, ButtonPress, ButtonPressMask, &mouse_selection, game);
	mlx_hook(game->win, MotionNotify, PointerMotionMask, &mouse_handle, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_window,
		game);
	mlx_loop(game->mlx);
}
