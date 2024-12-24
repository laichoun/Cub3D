/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_blank_game_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:27:11 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/18 17:08:54 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_blank_game(t_game *gamep)
{
	gamep->map = NULL;
	gamep->textures.img_no = NULL;
	gamep->textures.img_so = NULL;
	gamep->textures.img_ea = NULL;
	gamep->textures.img_we = NULL;
	gamep->textures.f_rgb = -1;
	gamep->textures.c_rgb = -1;
}
