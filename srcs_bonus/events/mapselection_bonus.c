/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapselection_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:41:43 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/18 17:14:01 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	handle_map_menu(int key, t_game *game)
{
	(void) key;
	//This is only for testing
	/*pseudo:
	* init_map(game)	// sets up map and game variable needed for the game from the file
	*					// the chosen file depends on the input of the player
	*/
	if (key == XK_1)
	{
		if (new_map(game, "maps/bonus/castle_1.cub") == FAILURE)
			return (free_game(game), (void)0);
		game->state = 2;
	}
}
