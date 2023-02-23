/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz-m <ddiniz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:45:59 by ddiniz-m          #+#    #+#             */
/*   Updated: 2023/02/23 19:33:09 by ddiniz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define PATH_SEA "sprites/Sea.xpm"
# define PATH_LAND "sprites/Land.xpm"
# define PATH_COLLECT1 "sprites/Collectible1.xpm"
# define PATH_COLLECT2 "sprites/Collectible2.xpm"
# define PATH_COLLECT3 "sprites/Collectible3.xpm"
# define PATH_COLLECT4 "sprites/Collectible4.xpm"
# define PATH_COLLECT5 "sprites/Collectible5.xpm"
# define PATH_PLAYER "sprites/Player.xpm"
# define PATH_EXIT1 "sprites/Exit.xpm"
# define PATH_EXIT2 "sprites/Exit2.xpm"

# define TILE_SIZE 64

typedef struct s_tile
{
	int			x;
	int			y;
}				t_tile;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_image
{
	void		*sea_img;
	void		*land_img;
	void		*collect1_img;
	void		*collect2_img;
	void		*collect3_img;
	void		*collect4_img;
	void		*collect5_img;
	void		*player_img;
	void		*exit1_img;
	void		*exit2_img;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_size_x;
	int			win_size_y;
	int			map_y;
	int			map_x;
	char		**tile_map;
	char		**map_buff;
	int			collect;
	int			collect_og;
	t_tile		tile;
	t_image		image;
	t_player	player;
}				t_game;

// ------------------------------  SO LONG -------------------------------
int				close_game(t_game *game);
void			put_tiles(char **map, t_game *game);
int				open_images(t_game *game);
int				input(int key, t_game *game);
int				render_frames(t_game *game);
int				errors(t_game *game, char *ber_file);
int				map_init(t_game *game);
void			ft_free(t_game*game, char **map);
// ------------------------------  LIBFT----------------------------------
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, char *src);
int				ft_strlen(char *str);
char			*ft_strstr(char *str, char *to_find);
// ------------------------------FT_PRINTF--------------------------------
int				ft_printf(const char *str, ...);
int				ft_puthexa(unsigned long long nbr,
					unsigned long long base, int i);
int				ft_check(char str, va_list args);
int				ft_putstr(char *str);
int				ft_putchar(char c);
int				ft_putnbr(int nb);
int				ft_putptr(unsigned long nbr);
// ---------------------------------GNL-----------------------------------
char			*get_next_line(int fd);
char			*get_lines(char *line, char res);

#endif
