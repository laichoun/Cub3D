/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startscreen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:11:45 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/20 14:21:29 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_startscreen(t_game *game, int frame);

void	render_startscreen(t_game *game)
{
	// static int	frame = 0;
	// static int	anim_speed = 600;
	// static int	frame_count = 0;

	// ++frame_count;
	// if (frame_count >= anim_speed)
	// {
	// 	frame = (frame + 1) % 2;
	// 	frame_count = 0;
	// }
	//draw_startscreen(game, frame);
	mlx_put_image_to_window(game->mlx, game->win, game->start[0], 0, 0);
}

void	draw_startscreen(t_game *game, int frame)
{
	if (frame == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->start[0], 0, 0);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->start[1], 0, 0);
}
