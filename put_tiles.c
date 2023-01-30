#include "so_long.h"

int	image_to_window(char tile, t_game *game)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->tileimg.land_img,
				game->tileimg.x, game->tileimg.y);
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->tileimg.sea_img,
				game->tileimg.x, game->tileimg.y);
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->tileimg.collect_img,
				game->tileimg.x, game->tileimg.y);
	if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->tileimg.exit_img,
				game->tileimg.x, game->tileimg.y);
	if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->tileimg.player_img,
				game->tileimg.x, game->tileimg.y);
	return (0);
}

void	put_tiles(char **tile_map, t_game *game)
{
	int	i;
	int	j;
	int	win_sizex;
	int	win_sizey;

	i = 0;
	j = 0;
	win_sizex = 512;
	win_sizey = 320;
	game->tileimg.y = 0;
	while ((game->tileimg.y <= win_sizey - tile_size))
	{
		game->tileimg.x = 0;
		while (i * tile_size <= win_sizex)
		{
			image_to_window(tile_map[j][i], game);
			game->tileimg.x += tile_size;
			i++;
		}
		i = 0;
		j++;
		game->tileimg.y += tile_size;
	}
}
