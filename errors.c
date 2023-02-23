/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:44 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/23 16:41:38 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// line counter and component checker
// returns -1 if components are not the correct amount
// returns number of lines (map_y)
// defines number of collectibles (collect_og)
int	map_lines(int fd, t_game *game)
{
	int		j;
	char	buf;

	j = 0;
	game->map_y = 1;
	game->collect_og = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			game->map_y++;
		if (buf == 'C')
			game->collect_og++;
		if (buf == 'P' || buf == 'E')
			j++;
		if (buf != '0' && buf != '1' && buf != 'P' && buf != 'C'
			&& buf != 'E' && buf != '\n')
			return (-1);
	}
	if (j != 2 || game->collect_og <= 0)
		return (-1);
	return (game->map_y);
}

// .ber to **char converter
// returns 1 if map_lines return -1
// returns 2 if malloc fails
int	map(t_game *game, char *ber_file)
{
	int		j;
	int		i;
	int		fd;

	j = 0;
	fd = open(ber_file, O_RDONLY);
	i = map_lines(fd, game);
	if (i < 0)
		return (1);
	game->tile_map = malloc(sizeof(char *) * (i + 1));
	close(fd);
	fd = open(ber_file, O_RDONLY);
	while (j < i)
	{
		game->tile_map[j] = get_next_line(fd);
		j++;
	}
	close(fd);
	return (0);
}

int	check_rect_wall(t_game *game, char **map)
{
	int	line;
	int	col;

	col = 0;
	line = 0;
	while (map[0][col] == '1')
		col++;
	while (map[line] && map[line][0] == '1')
		line++;
	game->map_y = line;
	game->map_x = col;
	line = 0;
	col = 0;
	while (map[game->map_y - 1][col] == '1')
		col++;
	while (map && map[line] && map[line][game->map_x - 1] == '1')
		line++;
	if (line != game->map_y || col != game->map_x)
		return (-1);
	return (1);
}

int	errors(t_game *game, char *ber_file)
{
	int	i;

	i = map(game, ber_file);
	if (i == 1)
	{
		ft_printf("Error\nMap doesn't contain the correct components\n");
		return (-1);
	}
	if (i == -1)
	{
		ft_printf("Error\nMap memory allocation error\n");
		return (-1);
	}
	if (check_rect_wall(game, game->tile_map) < 0)
	{
		ft_printf("Error\nMap not rectangular or not surrounded by walls\n");
		return (-1);
	}
	return (0);
}
