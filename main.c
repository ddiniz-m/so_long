#include "so_long.h"

/* int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
void	mlx_hook(t_win_list *win_ptr, int x_event, int x_mask, int (*f)(),
			void *param);
char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,
			int *size_line,int *endian);
int		mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img,
			int x,int y);
int	mlx_key_hook(t_win_list *win, int (*funct)(),void *param); 
int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);*/


/* int	key_hook(int keycode, t_window *win)
{
	t_image image;
	int i = 0;
	int j = 0;
	int side = 50;
	if(keycode == 115)
	{
		put_square(&image, side, i, j);
		j++;
	}
	return(0);
}

int render_next_frame(void *strcut)
{
	t_window window;
	t_image image;
	int i = 0;
	int j = 0;
	int side = 50;
	mlx_key_hook(window.win, key_hook, &window);
} */

int	main(void)
{
	t_window window;
	t_image image;
	int i = 0;
	int j = 0;
	int n = 0;
	int side = 50;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 500, 500, "New Window");
	image.img = mlx_new_image(window.mlx, 500, 500);
	image.address = mlx_get_data_addr(image.img, &image.bits, &image.line_len,
			&image.endian);
	while(n * side <= 400)
	{
		put_square(&image, side, i, j);
		i = i + side;
		j = j + side;
		n++;
	}
	/* mlx_loop_hook(window.mlx, render_next_frame, window.win); */
	mlx_put_image_to_window(window.mlx, window.win, image.img, 0, 0);
	mlx_key_hook(window.win, close_game, &window.win);
	mlx_loop(window.mlx);
}