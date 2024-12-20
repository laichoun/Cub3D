/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapselection_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:41:43 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/20 11:54:10 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	map_menu(t_game *game)
{
	game->level[0] = "maps/bonus/castle_1.cub";
	game->level[1] = "maps/bonus/castle_2.cub";
	game->level[2] = "maps/bonus/castle_3.cub";
	game->level[3] = "maps/bonus/castle_4.cub";
	game->level[4] = "maps/bonus/castle_5.cub";
	game->level[5] = "maps/bonus/castle_6.cub";
	game->level[6] = "maps/bonus/castle_7.cub";
	game->level[7] = "maps/bonus/castle_8.cub";
	game->level[8] = "maps/bonus/castle_9.cub";
	game->level[9] = "maps/bonus/castle_10.cub";
	game->mapid = 0;
	game->menuid = 0;
	return (SUCCESS);
}

char	*get_level_name(int key, t_game *game)
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

	level = get_level_name(key, game);
	if (!level)
		return ((void)0);
	if (new_map(game, get_level_name(key, game)) == FAILURE)
		return ((void)0);
	game->state = 2;
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
