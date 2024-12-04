/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:29:17 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 16:49:29 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// TODO: Rework this shit

void	print_error_message_1(int err_code, char *info);
void	print_error_message_2(int err_code, char *info);

void	err_msg(int err_code, char *info)
{
	if (err_code <= 9)
		print_error_message_1(err_code, info);
	else if (err_code > 9)
		print_error_message_2(err_code, info);
	else
		ft_fprintf(2, "Error: unexpected %d\n", err_code);
}

void	print_error_message_1(int err_code, char *info)
{
	if (err_code == ERROR_OPEN)
		ft_fprintf(2, "Error: Failed to open file %s\n", info);
	else if (err_code == ERROR_MALLOC)
		ft_fprintf(2, "Error: malloc failed\n");
	else if (err_code == ERROR_CARDINAL)
		ft_fprintf(2, "Error: Cardinal Textures missing\n");
	else if (err_code == ERROR_FLOOR)
		ft_fprintf(2, "Error: Color code missing\n");
	else if (err_code == ERROR_MISSING_INFO)
		ft_fprintf(2, "Error: Textures or Colors missing\n");
	else if (err_code == ERROR_MAP)
		ft_fprintf(2, "Error: Invalid map\n");
	else if (err_code == ERROR_MAPMISSING)
		ft_fprintf(2, "Error: MAP is missing\n");
	else if (err_code == ERROR_INVALID_RGB)
		ft_fprintf(2,
			"Error: Color code is not a number"
			",is exceeding 255 or is a negative color code\n");
	else if (err_code == ERROR_WRONG_NBR_ARG)
		ft_fprintf(2, "Error: Wrong number of argument put a file.cub\n");
}

void	print_error_message_2(int err_code, char *info)
{
	if (err_code == ERROR_MLX)
		ft_fprintf(2, "Error: mlx_init failed\n");
	else if (err_code == ERROR_MAP_DIM)
		ft_fprintf(2, "Error: Map dimension too small\n");
	else if (err_code == ERROR_INVALID_ID)
		ft_fprintf(2, "ERROR: Invalid color identifier\n");
	else if (err_code == ERROR_CARDINAL_DUP_MISS)
		ft_fprintf(2, "Error: Cardinal missing or repeat.\n");
	else if (err_code == ERROR_WRONG_CARDINAL)
		ft_fprintf(2, "ERROR: Wrong Cardinals given\n");
	else if (err_code == ERROR_PLAYER)
		ft_fprintf(2, "Error: Wrong number of player\n");
	else if (err_code == ERROR_NOT_SURROUNDED)
		ft_fprintf(2, "Error: MAP not surrounded by walls\n");
	else if (err_code == ERROR_WRONG_EXTENSION)
		ft_fprintf(2, "Error: Wrong file extension %s\n", info);
	else if (err_code == ERROR_NO_EXTENSION)
		ft_fprintf(2, "Error: No file extension\n");
	else if (err_code == ERROR_FILE)
		ft_fprintf(2, "Error: Invalid file name: %s\n", info);
	else if (err_code == ERROR_CHAR)
		ft_fprintf(2, "Error: Wrong components\n");
}

/*
void	err_msg(int err_code, char *info)
{
	if (err_code == ERROR_OPEN)
		ft_fprintf(2, "Error: Failed to open file %s\n", info);
	else if (err_code == ERROR_MALLOC)
		ft_fprintf(2, "Error: malloc failed\n");
	else if (err_code == ERROR_MISSING_INFO)
		ft_fprintf(2, "Error: Textures or Colors missing\n");
	else if (err_code == ERROR_CARDINAL)
		ft_fprintf(2, "Error: Cardinal Textures missing\n");
	else if (err_code == ERROR_FLOOR)
		ft_fprintf(2, "Error: Color code missing\n");
	else if (err_code == ERROR_MAP)
		ft_fprintf(2, "Error: Invalid map\n");
	else if (err_code == ERROR_MLX)
		ft_fprintf(2, "Error: mlx_init failed\n");
	else if (err_code == ERROR_MAP_DIM)
		ft_fprintf(2, "Error: Map dimension too small\n");
	else if (err_code == ERROR_INVALID_ID)
		ft_fprintf(2, "ERROR: Invalid color identifier\n");
	else if (err_code == ERROR_INVALID_RGB)
		ft_fprintf(2,
					"Error: Color code is not a number"
					",is exceeding 255 or is a negative color code\n");
	else if (err_code == ERROR_CARDINAL_DUP_MISS)
		ft_fprintf(2, "Error: Cardinal missing or repeat.\n");
	else if (err_code == ERROR_WRONG_CARDINAL)
		ft_fprintf(2, "ERROR: Wrong Cardinals given\n");
	else if (err_code == ERROR_PLAYER)
		ft_fprintf(2, "Error: Wrong number of player\n");
	else if (err_code == ERROR_NOT_SURROUNDED)
		ft_fprintf(2, "Error: MAP not surrounded by walls\n");
	else if (err_code == ERROR_WRONG_EXTENSION)
		ft_fprintf(2, "Error: Wrong file extension %s\n", info);
	else if (err_code == ERROR_NO_EXTENSION)
		ft_fprintf(2, "Error: No file extension\n");
	else if (err_code == ERROR_WRONG_NBR_ARG)
		ft_fprintf(2, "Error: Wrong number of argument put a file.cub\n");
	else if (err_code == ERROR_MAPMISSING)
		ft_fprintf(2, "Error: MAP is missing\n");
	else if (err_code == ERROR_FILE)
		ft_fprintf(2, "Error: Invalid file name: %s\n", info);
	else
		ft_fprintf(2, "Error: unexpected %d\n", err_code);
}
*/
