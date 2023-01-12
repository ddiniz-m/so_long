#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"

/* int		mlx_destroy_window(void *mlx_ptr, void *win_ptr); */
/* void		mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask,
				int (*f)(), void *param) */
/* char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,
			   int *size_line,int *endian) */

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

/* int close_window(int keycode, t_window *win)
{
	t_image		image;
	t_window	window;
	void		*mlx;

	return(mlx_destroy_window(window->mlx, window->win));
} */
/* int	key_hook(int keycode, t_window *win)
{
	(void) keycode;
	(void) win;
	return(printf("Key was pressed\n"));
} */

void put_pixel(t_image *image, int x, int y, int color)
{
	char *pixel;
	int correct;

	correct = (y * image->line_len) + ( x * (image->bits / 8));
	pixel = image->address + correct;
	*(unsigned int *)pixel= color;
}
int	main(void)
{
	t_window	window;
	t_image		image;
	int correct;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 500, 500, "New Window");
	image.img = mlx_new_image(window.mlx, 500, 500);
	image.address = mlx_get_data_addr(image.img, &image.bits, &image.line_len, 
										&image.endian);
	put_pixel(&image)
	/* mlx_hook(window.win, 2, 1L<<0 ,key_hook, &window); */
	/* mlx_hook(window.win, 3, 0 ,close_window, &win); */
	mlx_loop(window.mlx);
	(void)window.win;
}
