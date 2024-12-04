/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:01 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 13:16:47 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	init_raycast(t_game *game, t_file *file)
{
	game->pos_x = (float) file->player_x;
	game->pos_y = (float) file->player_y;
	return (SUCCESS);
}
