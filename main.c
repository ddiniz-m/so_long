#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"

/* int		mlx_destroy_window(void *mlx_ptr, void *win_ptr); */
/* void		mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param) */


typedef struct s_list{
	void *mlx;
	void *win;
}	t_list;

/* int close_window(int keycode, t_list *list)
{
	return(mlx_destroy_window(list->mlx, list->win));
}
 */
int	key_hook(int keycode, t_list *list)
{
	return(printf("Key was pressed\n"));
}

int main()
{
	t_list	list;

	list.mlx = mlx_init();
	list.win = mlx_new_window(list.mlx, 500, 500, "New Window");
	mlx_hook(list.win, 2, 1L<<0 ,key_hook, &list);
	mlx_loop(list.mlx);
	(void) list.win;
}


/* enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}; */