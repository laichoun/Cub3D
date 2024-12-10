/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:14 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 13:18:19 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <math.h>

void	torch_anim(t_game *game, int key);

int	key_handle(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	else if (key == XK_space)
		space_key(game);
	else if (key == XK_w)
		w_key(game);
	else if (key == XK_s)
		s_key(game);
	else if (key == XK_a)
		a_key(game);
	else if (key == XK_d)
		d_key(game);
	else if (key == XK_Right)
		right_arrow_key(game);
	else if (key == XK_Left)
		left_arrow_key(game);
	else if (key == XK_Return)
		game->state = 1;
	torch_anim(game, key);
	return (SUCCESS);
}

void	torch_anim(t_game *game, int key)
{
	const double	step = 0.06;
	const double	scale = 90;
	static double	c = 0.0;
	static int		dir = 1;

	if (key == XK_w || key == XK_s || key == XK_a || key == XK_d)
	{
		if (c + step > 1 || c - step < -1)
			dir *= -1;
		c = c + dir * step;
		game->t_coefx = cos(c * M_PI) * scale;
		game->t_coefy = (sin(-fabs(c) * M_PI) / 2) * scale;
	}
}
