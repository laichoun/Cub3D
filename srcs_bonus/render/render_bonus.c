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
void	fps(t_game *game, struct timeval cur);

int	render(t_game *game)
{
	static struct timeval	last;
	struct timeval			cur;

	if (gettimeofday(&cur, NULL) == -1)
		return (FAILURE);
	if (game->state == 0)
		render_startscreen(game);
	/*else if ((cur.tv_sec - last.tv_sec) * 1000 + (cur.tv_usec - last.tv_usec)
		/ 1000 >= 1000 / 30)*/
	else {
		render_raycast(game);
		draw_minimap(game);
		render_animation(game);
		player_actions(game);
		mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
		fps(game, cur);
		last = cur;
	}
	return (SUCCESS);
}

void	fps(t_game *game, struct timeval cur)
{
	static struct timeval	fps;
	static int				count = 0;
	static int				last_count = 0;
	char					*num;

	if ((cur.tv_sec - fps.tv_sec) * 1000 + (cur.tv_usec - fps.tv_usec)
		/ 1000 >= 1000)
	{
		last_count = count;
		count = 0;
		fps = cur;
	}
	num = ft_itoa(last_count);
	if (!num)
		return ((void)0);
	mlx_set_font(game->mlx, game->win,
		"-misc-fixed-bold-r-normal--18-120-100-100-c-90-iso8859-9");
	mlx_string_put(game->mlx, game->win, 0, 15, 0xFFFF00, num);
	++count;
	free(num);
}
