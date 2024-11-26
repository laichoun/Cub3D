#include "../../includes/cub3d.h"

void display_game_data(t_game game)
{
	int i;
	int j;

	i = -1;
	ft_printf("map:\n");
	while (game.map[++i])
	{
		j = -1;
		while (game.map[i][++j])
			ft_printf("%c ",game.map[i][j]);
		ft_printf("\n");
	}
	ft_printf("num of row: %d\nnum of col: %d\n", game.row, game.col);
	ft_printf("Floor: (%d,%d,%d)\n", game.textures.f_rgb[0], game.textures.f_rgb[1],
			game.textures.f_rgb[2]);
	ft_printf("Ceiling: (%d,%d,%d)\n", game.textures.c_rgb[0], game.textures.c_rgb[1],
			game.textures.c_rgb[2]);
	ft_printf("Player pos: (%d,%d)\n", game.player_x, game.player_y);
}

void	display_file(t_file f)
{
	ft_printf("File:\n");
	ft_display_split(f.cp_file);
	ft_printf("Map:\n");
	ft_display_split(f.map);
	ft_printf("count: \n");
	ft_printf("\tNO: %d\n", f.no);
	ft_printf("\tSO: %d\n", f.so);
	ft_printf("\tEA: %d\n", f.ea);
	ft_printf("\tWE: %d\n", f.we);
	ft_printf("textures files: \n");
	ft_printf("\tNO: %s\n", f.tex_no);
	ft_printf("\tSO: %s\n", f.tex_so);
	ft_printf("\tEA: %s\n", f.tex_ea);
	ft_printf("\tWE: %s\n", f.tex_we);
	ft_printf("Floor: (%d,%d,%d)\n", f.f_rgb[0], f.f_rgb[1],
			f.f_rgb[2]);
	ft_printf("Ceiling: (%d,%d,%d)\n", f.c_rgb[0], f.c_rgb[1],
			f.c_rgb[2]);
}
