#ifndef SO_LONG_H

# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx_linux/mlx.h"

# define	path_sea "sprites/sea.xpm"
# define	path_land "sprites/land.xpm"
# define	path_collect "sprites/collect.xpm"
# define	path_player "sprites/player.xpm"
# define	path_exit "sprites/exit.xpm"

# define	tile_size 64

typedef struct s_tileimg
{
	void		*sea_img;
	void		*land_img;
	void		*collect_img;
	void		*player_img;
	void		*exit_img;
}				t_tile_img;

typedef struct s_image
{
	void		*img;
	char		*address;
	int			bits;
	int			line_len;
	int			endian;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**tile_map;
	t_tile_img	tile_img;
	t_image		image;
}				t_game;

void			put_square(t_image *image, int side, int startx, int starty);
void			put_pixel(t_image *image, int x, int y, int color);
int				close_game(int keycode, t_game *game);
char			**map(t_game *game, char *ber_file);
int				check_rect_wall(char **map);
int				map_lines(int fd);
void			put_tiles(char **map, t_game *game);
void			open_images(t_game *game);

#endif
