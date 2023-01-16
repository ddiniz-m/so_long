#ifndef SO_LONG_H

# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

typedef struct s_window
{
	void	*mlx;
	void	*win;
}			t_window;

typedef struct s_image
{
	void	*img;
	char	*address;
	int		bits;
	int		line_len;
	int		endian;
}			t_image;

int		close_game(int keycode, t_window *window);
void		put_square(t_image *image, int side, int startx, int starty);
void	put_pixel(t_image *image, int x, int y, int color);

#endif