/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:05:21 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/20 15:54:18 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	render_mapselection(t_game *game);
void	fps(t_game *game, struct timeval cur);

void	render_game(t_game *game)
{
	render_raycast(game);
	draw_minimap(game);
	render_animation(game);
	player_actions(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
}

int	render(t_game *game)
{
	static struct timeval	last;
	struct timeval			cur;

	if (gettimeofday(&cur, NULL) == -1)
		return (FAILURE);
	if ((cur.tv_sec - last.tv_sec) * 1000 + (cur.tv_usec - last.tv_usec)
		/ 1000 >= 1000 / 30)
	{
		if (game->state == 0)
			render_menuselection(game);
		else if (game->state == 1)
			render_mapselection(game);
		else if (game->state == 2 && game->mapid < 10)
			render_game(game);
		else if (game->state == 3)
			mlx_put_image_to_window(game->mlx, game->win, game->start[7], 0, 0);
		else if (game->state == 4)
			mlx_put_image_to_window(game->mlx, game->win, game->start[6], 0, 0);
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
