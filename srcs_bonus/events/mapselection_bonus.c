/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapselection_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:41:43 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/19 17:05:42 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"


int	map_menu(t_game *game)
{
	game->level[0] = "maps/bonus/castle_1.cub";
	game->level[1] = "maps/bonus/castle_2.cub";
	game->mapid = 0;
	return (SUCCESS);
}

char	*get_level(int key, t_game *game)
{
	if (key >= XK_1 && key <= XK_9)
	{
		game->mapid = key - XK_1;
		return (game->level[key - XK_1]);
	}
	return (NULL);
}

void	handle_map_menu(int key, t_game *game)
{
	char	*level;

	level = get_level(key, game);
	if (!level)
		return ((void)0);
	if (new_map(game, get_level(key, game)) == FAILURE)
		return ((void)0);
	game->state = 2;
}


/*
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
*/

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
