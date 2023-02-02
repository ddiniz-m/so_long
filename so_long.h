#ifndef SO_LONG_H

# define SO_LONG_H

/* # include "ft_printf/ft_printf.h" */
/* # include "libft/libft.h" */
# include "../mlx_linux/mlx.h"
# include "gnl/get_next_line.h"

# define path_sea "sprites/sea.xpm"
# define path_land "sprites/land.xpm"
# define path_collect "sprites/collect.xpm"
# define path_player "sprites/player.xpm"
# define path_exit "sprites/exit.xpm"

# define tile_size 64

typedef struct s_type
{
	void		*Wall;
/* 	void		*Sea;
	void		*Exit;
	void		*Player;
	void		*Collect; */
}				t_type;

typedef struct s_tile
{
	int			x;
	int			y;
	void		*up;
	void		*down;
	void		*left;
	void		*right;
}				t_tile;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_image
{
	/*void		*img;
	char		*address;
	int			bits;
	int			line_len;
	int			endian; */
	void		*sea_img;
	void		*land_img;
	void		*collect_img;
	void		*player_img;
	void		*exit_img;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			map_y;
	int			map_x;
	char		**tile_map;
	t_type		type;
	t_tile		tile;
	t_image		image;
	t_player	player;
}				t_game;

void			put_square(t_image *image, int side, int startx, int starty);
void			put_pixel(t_image *image, int x, int y, int color);
int				close_game(t_game *game);
int				map(t_game *game, char *ber_file);
int				check_rect_wall(t_game *game, char **map);
int				map_lines(int fd, t_game *game);
void			put_tiles(char **map, t_game *game);
int				open_images(t_game *game);
int				input(int key, t_game *game);
int				player_move(t_game *game);
int				render_frames(t_game *game);
int				errors(t_game *game);

#endif
