/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handle_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:33:44 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/20 15:55:07 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	handle_game_keypress(int key, t_game *game);
void	handle_map_menu(int key, t_game *game);

int	keypress_handle(int key, t_game *game)
{
	if (game->state == 1)
		handle_map_menu(key, game);
	else if (game->state == 2)
		handle_game_keypress(key, game);
	if (key == XK_Escape)
	{
		if (game->state == 2)
		{
			game->state = 0;
			game->mapid = 0;
			free_game(game);
		}
		else if (game->state == 1 || game->state == 3 || game->state == 4)
			game->state = 0;
	}
	return (SUCCESS);
}

void	handle_game_keypress(int key, t_game *game)
{
	if (key == XK_space)
		return (space_key(game), (void)0);
	else if (key == XK_w)
		game->key[0] = 1;
	else if (key == XK_a)
		game->key[1] = 1;
	else if (key == XK_s)
		game->key[2] = 1;
	else if (key == XK_d)
		game->key[3] = 1;
	else if (key == XK_Right)
		game->key[4] = 1;
	else if (key == XK_Left)
		game->key[5] = 1;
}
