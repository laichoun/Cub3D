/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:27:57 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/06 16:35:30 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

//void	init_minimap(t_game *game);
int	init_mlx(t_game *game, t_file *file)
{
	int	w;
	int	h;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (err_msg(ERROR_MLX, NULL), FAILURE);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->screen = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->textures.img_no = mlx_xpm_file_to_image(game->mlx, file->tex_no, &w,
			&h);
	game->textures.img_so = mlx_xpm_file_to_image(game->mlx, file->tex_so, &w,
			&h);
	game->textures.img_we = mlx_xpm_file_to_image(game->mlx, file->tex_we, &w,
			&h);
	game->textures.img_ea = mlx_xpm_file_to_image(game->mlx, file->tex_ea, &w,
			&h);
	return (SUCCESS);
}
