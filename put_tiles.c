/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:25:06 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/03 17:29:50 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//draws images based on respective tile
int	image_to_window(char tile, t_game *game)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->image.land_img,
			game->tile.x, game->tile.y);
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->image.sea_img,
			game->tile.x, game->tile.y);
	if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->image.exit_img,
			game->tile.x, game->tile.y);
	if (tile == 'C')
		tile = collectible_tile(game);
	if (tile == 'P')
		player_tile(game);
	return (0);
}

// changes collectibles to empty(Sea) when player reaches tile
// to understand: why || intead of &&

void	collect_img(int a, int b, t_game *game)
{
	if (b == a - 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.collect1_img, game->tile.x, game->tile.y);
	if (b == a - 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.collect2_img, game->tile.x, game->tile.y);
	if (b == a - 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.collect3_img, game->tile.x, game->tile.y);
	if (b == a)
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.collect4_img, game->tile.x, game->tile.y);
}

char	collectible_tile(t_game *game)
{
	static int	i;
	static int	a = 0;
	static int	b = 0;

	if (b == a)
		a += 4;
	if (b != a)
		b++;
	if ((game->tile.x != game->player.x || game->tile.y != game->player.y)
		&& i == 0)
	{
		collect_img(a, b, game);
		return ('C');
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image.sea_img,
		game->tile.x, game->tile.y);
	i++;
	return ('0');
}

void	player_tile(t_game *game)
{
	static int	i;

	if (i == 0)
	{
		i++;
		game->player.x = game->tile.x;
		game->player.y = game->tile.y;
	}
	if (i != 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->image.sea_img,
			game->tile.x, game->tile.y);
	}
}

void	put_tiles(char **tile_map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->tile.y = 0;
	while ((game->tile.y <= game->win_size_y - tile_size))
	{
		game->tile.x = 0;
		while (i * tile_size <= game->win_size_x)
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
