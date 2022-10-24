#include <mlx.h>
#include <stdio.h>

typedef struct s_list
{
	int *mlx;
	int *win;
	void	*img;
	void	*nimg;
	int	old_x;
	int old_y;
}				t_list;

int	mouse_hook( int x, int y, t_list *a)
{
	if (x > -1 && y > -1 && x < 701 && y < 701)
	{
		mlx_put_image_to_window(a->mlx, a->win, a->nimg, a->old_x, a->old_y);
		mlx_put_image_to_window(a->mlx, a->win, a->img, x, y);
		a->old_x = x;
		a->old_y = y;
	}
	else
		mlx_put_image_to_window(a->mlx, a->win, a->nimg, a->old_x, a->old_y);
	return (0);
}

int	main(void)
{
	t_list	a;
	char	relative_path[] = "./cursor.xpm";
	int		img_width;
	int		img_height;

	img_width = 0;
	img_height = 0;

	a.old_x = 0;
	a.old_y = 0;
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 700, 700, "wild cursor");
	a.img = mlx_xpm_file_to_image(a.mlx, relative_path, &img_width, &img_height);
	a.nimg = mlx_new_image ( a.mlx, 70, 70 );
	mlx_hook(a.win, 6, 0, mouse_hook, &a);
	mlx_loop(a.mlx);
	return 0;
}