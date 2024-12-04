/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:08 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 16:55:07 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	looping_youhouuuuuuuuuuuuuuu(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (err_msg(ERROR_WRONG_NBR_ARG, NULL), FAILURE);
	if (init_game(&game, argv[1]))
		return (FAILURE);
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

/*
static void	creation_minimap(t_game *game)
{
	mlx_loop_hook(game->mlx, minimap, game);
	mlx_loop(game->mlx);
}

void	minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->col)
	{
		j = 0;
		while (j < game->row)
		{
			if (game->map[i][j] == '1')
				draw_wall(game);
			else if (game->map[i][j] == '0')
				draw_floor(game);
			j ++;
		}
		i ++;
	}
}

void	draw_wall(t_game *game)
{
	
}
*/