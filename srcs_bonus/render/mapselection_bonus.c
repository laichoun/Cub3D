/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapselection_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:35:38 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/20 15:58:28 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	render_mapselection(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->start[5], 0, 0);
}

void	render_menuselection(t_game *game)
{
	if (game->menuid == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->start[1], 0, 0);
	else if (game->menuid == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->start[2], 0, 0);
	else if (game->menuid == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->start[3], 0, 0);
	else if (game->menuid == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->start[4], 0, 0);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->start[0], 0, 0);
}
