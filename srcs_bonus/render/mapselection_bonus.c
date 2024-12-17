/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapselection_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:35:38 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/17 17:36:50 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	render_mapselection(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->start[2], 0, 0);
}
