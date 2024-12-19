/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapselection_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:41:43 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/19 15:06:03 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
char	**creation_tab_map(t_game *game)
{
	int	i;

	i = 0;
}
*/

void	handle_map_menu(int key, t_game *game)
{
	if (key == XK_1)
	{
		if (new_map(game, "maps/bonus/castle_1.cub") == FAILURE)
			return ((void)0);
		game->state = 2;
	}
	if (key == XK_2)
	{
		if (new_map(game, "maps/bonus/castle_2.cub") == FAILURE)
			return ((void)0);
		game->state = 2;
	}
}

int	load_next_map(t_game *game)
{
	if (game->mapid < 1)
	{
		free_game(game);
		new_map(game, game->level[++game->mapid]);
	}
	else
		game->state = 3;
	return (SUCCESS);
}
