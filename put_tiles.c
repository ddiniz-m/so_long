#include "so_long.h"

void	put_tiles(char **tile_map, t_game *game)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	int win_sizex = 512;
	int win_sizey = 320;
	
	while((y <= win_sizey - tile_size))
	{
		while(i * tile_size <= win_sizex)
		{

			if (tile_map[j][i] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->tile_img.land_img, x, y);
			if (tile_map[j][i] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->tile_img.sea_img, x, y);
			if (tile_map[j][i] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->tile_img.collect_img, x, y);
			if (tile_map[j][i] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->tile_img.exit_img, x, y);
			if (tile_map[j][i] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->tile_img.player_img, x, y);
			x += tile_size;
			i++;
		}
		x = 0;
		i = 0;
		j++;
		y += tile_size;
	}
}