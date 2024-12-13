/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:05:21 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 18:05:38 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <stdio.h>

void	render_startscreen(t_game *game);

int	render(t_game *game)
{
	static struct timeval	last;
	static struct timeval	fps;
	static int				count = 0;
	struct timeval			cur;

	if (gettimeofday(&cur, NULL) == -1)
		return (FAILURE);
	if (game->state == 0)
		render_startscreen(game);
	else if ((cur.tv_sec - last.tv_sec) * 1000 + (cur.tv_usec - last.tv_usec) / 1000 >= 1000/30)
	{
		render_raycast(game);
		draw_minimap(game);
		render_animation(game);
		player_actions(game);
		if ((cur.tv_sec - fps.tv_sec) * 1000 + (cur.tv_usec - fps.tv_usec) / 1000 >= 1000)
		{
			printf("%d\n", count);
			count = 0;
			fps = cur;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
		last = cur;
		++count;
	}
	return (SUCCESS);
}
