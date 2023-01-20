#ifndef SO_LONG_H

# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_tileimg
{
	void		*sea_img;
	void		*land_img;
	void		*collect_img;
	void		*player_img;
	void		*exit_img;
}				t_tile_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_tile_img	tile_img;
}				t_game;

typedef struct s_image
{
	void		*img;
	char		*address;
	int			bits;
	int			line_len;
	int			endian;
}				t_image;

void			put_square(t_image *image, int side, int startx, int starty);
void			put_pixel(t_image *image, int x, int y, int color);
int				close_game(int keycode, t_game *game);
char			**map(char *ber_file);

#endif
