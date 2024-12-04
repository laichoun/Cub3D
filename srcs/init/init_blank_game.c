/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_blank_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:27:11 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 11:27:12 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	blank_textures(t_game *gamep);

void	init_blank_game(t_game *gamep)
{
	blank_textures(gamep);
	gamep->map = NULL;
	gamep->mlx = NULL;
	gamep->screen = NULL;
	gamep->win = NULL;
}

void	blank_textures(t_game *gamep)
{
	gamep->textures.img_no = NULL;
	gamep->textures.img_so = NULL;
	gamep->textures.img_ea = NULL;
	gamep->textures.img_we = NULL;
	gamep->textures.f_rgb = -1;
	gamep->textures.c_rgb = -1;
}
