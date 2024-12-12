/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease_handle_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:54:16 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 17:41:51 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	keyrelease_handle(int key, t_game *game)
{
	if (key == XK_w)
		game->key[0] = 0;
	else if (key == XK_a)
		game->key[1] = 0;
	else if (key == XK_s)
		game->key[2] = 0;
	else if (key == XK_d)
		game->key[3] = 0;
	else if (key == XK_Right)
		game->key[4] = 0;
	else if (key == XK_Left)
		game->key[5] = 0;
	return (SUCCESS);
}
