/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:29:17 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/24 11:06:55 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	print_error_message_1(int err_code, char *info);
void	print_error_message_2(int err_code, char *info);

void	err_msg(int err_code, char *info)
{
	if (err_code <= 9)
		print_error_message_1(err_code, info);
	else if (err_code > 9)
		print_error_message_2(err_code, info);
	else
		ft_fprintf(2, "Error\nunexpected %d\n", err_code);
}

void	print_error_message_1(int err_code, char *info)
{
	if (err_code == ERROR_OPEN)
		ft_fprintf(2, "Error\nFailed to open file %s\n", info);
	else if (err_code == ERROR_MALLOC)
		ft_fprintf(2, "Error\nmalloc failed\n");
	else if (err_code == ERROR_CARDINAL)
		ft_fprintf(2, "Error\nCardinal Textures missing\n");
	else if (err_code == ERROR_FLOOR)
		ft_fprintf(2, "Error\nColor code missing\n");
	else if (err_code == ERROR_MISSING_INFO)
		ft_fprintf(2, "Error\nTextures or Colors missing\n");
	else if (err_code == ERROR_MAP)
		ft_fprintf(2, "Error\nInvalid map\n");
	else if (err_code == ERROR_MAPMISSING)
		ft_fprintf(2, "Error\nMAP is missing\n");
	else if (err_code == ERROR_INVALID_RGB)
		ft_fprintf(2,
			"Error\nColor code is not a number"
			",is exceeding 255 or is a negative color code\n");
	else if (err_code == ERROR_WRONG_NBR_ARG)
		ft_fprintf(2, "Error\nNo arguments expected\n");
}

void	print_error_message_2(int err_code, char *info)
{
	if (err_code == ERROR_MLX)
		ft_fprintf(2, "Error\nmlx_init failed\n");
	else if (err_code == ERROR_MAP_DIM)
		ft_fprintf(2, "Error\nMap dimension too small\n");
	else if (err_code == ERROR_INVALID_ID)
		ft_fprintf(2, "ERROr\nInvalid color identifier\n");
	else if (err_code == ERROR_CARDINAL_DUP_MISS)
		ft_fprintf(2, "Error\nCardinal missing or repeat.\n");
	else if (err_code == ERROR_WRONG_CARDINAL)
		ft_fprintf(2, "ERROr\nWrong Cardinals given\n");
	else if (err_code == ERROR_PLAYER)
		ft_fprintf(2, "Error\nWrong number of player\n");
	else if (err_code == ERROR_NOT_SURROUNDED)
		ft_fprintf(2, "Error\nMAP not surrounded by walls\n");
	else if (err_code == ERROR_WRONG_EXTENSION)
		ft_fprintf(2, "Error\nWrong file extension %s\n", info);
	else if (err_code == ERROR_NO_EXTENSION)
		ft_fprintf(2, "Error\nNo file extension\n");
	else if (err_code == ERROR_FILE)
		ft_fprintf(2, "Error\nInvalid file name: %s\n", info);
	else if (err_code == ERROR_CHAR)
		ft_fprintf(2, "Error\nWrong components\n");
}
