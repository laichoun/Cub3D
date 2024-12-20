/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapselection_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:35:38 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/20 14:31:41 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	render_mapselection(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->start[5], 0, 0);
}


void	render_menuselection(t_game *game)
{
	if (game->mapid == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->start[0], 0, 0);
	if (game->mapid == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->start[1], 0, 0);
	if (game->mapid == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->start[2], 0, 0);	
	if (game->mapid == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->start[3], 0, 0);
}