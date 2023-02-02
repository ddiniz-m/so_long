#include "so_long.h"

int	image_to_window(char tile, t_game *game)
{
	static int i;
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->image.land_img,
				game->tile.x, game->tile.y);
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image.sea_img,
				game->tile.x, game->tile.y);
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->image.collect_img,
				game->tile.x, game->tile.y);
	if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->image.exit_img,
				game->tile.x, game->tile.y);
	if (tile == 'P' && i == 0)
	{
		i++;
		game->player.x = game->tile.x;
		game->player.y = game->tile.y;
	}
	if(tile == 'P' && i != 0)
		mlx_put_image_to_window(game->mlx, game->win, game->image.sea_img,
				game->tile.x, game->tile.y);
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
	game->tile.y = 0;
	while ((game->tile.y <= win_sizey - tile_size))
	{
		game->tile.x = 0;
		while (i * tile_size <= win_sizex)
		{
			image_to_window(tile_map[j][i], game);
			game->tile.x += tile_size;
			i++;
		}
		i = 0;
		j++;
		game->tile.y += tile_size;
	}
}
