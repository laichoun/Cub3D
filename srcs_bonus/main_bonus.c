/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:08 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/05 17:37:03 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

//static void	looping_youhouuuuuuuuuuuuuuu(t_game *game);

static int	draw_minimap(t_game *game);
//static void	creation_minimap(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (err_msg(ERROR_WRONG_NBR_ARG, NULL), FAILURE);
	if (init_game(&game, argv[1]))
		return (FAILURE);
	draw_minimap(&game);
	//looping_youhouuuuuuuuuuuuuuu(&game);
	//creation_minimap(&game);
	free_game(&game);
	return (0);
}

/*
static void	looping_youhouuuuuuuuuuuuuuu(t_game *game)
{
	mlx_loop_hook(game->mlx, render, game);
	//mlx_loop_hook(game->mlx, draw_minimap, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &key_handle, game);
	mlx_hook(game->win, MotionNotify, PointerMotionMask, &mouse_handle, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_window,
		game);
	mlx_loop(game->mlx);
}
*/


/*
static void	creation_minimap(t_game *game)
{
	mlx_loop_hook(game->mlx, draw_minimap, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_window,
		game);
	mlx_loop(game->mlx);
}
*/
static int	draw_minimap(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	float	scale_x; 
	float	scale_y;
	int		pos_x;
	int		pos_y;

	while (++i < game->col)
	{
		j = 0;
		while (j < game->row)
		{
		
			if (game->map[i][j] == '1')
			{
				scale_x = (float)MINI_WIDTH / (float)(game->col * game->minimap.walls->width);
				scale_y = (float)MINI_HEIGHT / (float)(game->row * game->minimap.walls->height);
				pos_x = i * scale_x * game->minimap.walls->width;
				pos_y = j * scale_y * game->minimap.walls->height;
				//mlx_put_image_to_window(game->mlx, game->win, game->minimap.walls, pos_y, pos_x);
				printf("char : %c, pos x : %d, pos y : %d\n", game->map[i][j], pos_x, pos_y);
			}
			else if (game->map[i][j] == '0')
			{
				scale_x = (float)MINI_WIDTH / (float)(game->col * game->minimap.floor->width);
				scale_y = (float)MINI_HEIGHT / (float)(game->row * game->minimap.floor->height);
				pos_x = i * scale_x * game->minimap.floor->width;
				pos_y = j * scale_y * game->minimap.floor->height;
				//mlx_put_image_to_window(game->mlx, game->win, game->minimap.floor, pos_y, pos_x);
				printf("char : %c, pos x : %d, pos y : %d\n", game->map[i][j], pos_x, pos_y);
			}
	
			else if (game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'W' || game->map[i][j] == 'S')
			{
				scale_x = (float)MINI_WIDTH / (float)(game->col * game->minimap.player->width);
				scale_y = (float)MINI_HEIGHT / (float)(game->row * game->minimap.player->height);
				pos_x = i * scale_x * game->minimap.player->width;
				pos_y = j * scale_y * game->minimap.player->height;
				//mlx_put_image_to_window(game->mlx, game->win, game->minimap.player, pos_y, pos_x);
				printf("char : %c, pos x : %d, pos y : %d\n", game->map[i][j], pos_x, pos_y);	
			}
			
			j++;
		}
	}
	return (SUCCESS);
}

