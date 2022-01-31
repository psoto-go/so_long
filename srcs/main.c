/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:43:34 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 12:48:07 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_mlx *img)
{
	if (keycode == 53)
		mlx_destroy_window(img->mlx, img->win);
	return (0);
}

int	key_hook_in(int x ,int y)
{
	ft_printf("%s %d x %d y", "Hola", x, y);
	return (0);
}

int	key_hook_out(int x ,int y)
{
	ft_printf("%s %d x %d y", "adios", x, y);
	return (0);
}

int		exit_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return(0);
}

int 	check_key(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit_mlx(mlx);
	return (0);
}

void	load_images(t_mlx *mlx)
{
	char	*p1;
	char	*p0;
	char	*c;
	char	*e;
	char	*p;

	p1 = "img/cubo.xpm";
	p0 = "img/cesped.xpm";
	c = "img/surf.xpm";
	e = "img/mar.xpm";
	p = "img/mario.xpm";

	mlx->img.img1 = mlx_xpm_file_to_image(mlx->mlx, p1, &mlx->map.x, &mlx->map.y);
	mlx->img.img2 = mlx_xpm_file_to_image(mlx->mlx, p0, &mlx->map.x, &mlx->map.y);
	mlx->img.img3 = mlx_xpm_file_to_image(mlx->mlx, c, &mlx->map.x, &mlx->map.y);
	mlx->img.img4 = mlx_xpm_file_to_image(mlx->mlx, e, &mlx->map.x, &mlx->map.y);
	mlx->img.img5 = mlx_xpm_file_to_image(mlx->mlx, p, &mlx->map.x, &mlx->map.y);
}

void	load_map(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (mlx->map.map[i])
	{
		j = 0;
		while(mlx->map.map[i][j])
		{
			if (mlx->map.map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img1, j * 100, i * 100 );
			else if (mlx->map.map[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img2, j * 100, i * 100 );
			else if (mlx->map.map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img3, j * 100, i * 100 );
			else if (mlx->map.map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img4, j * 100, i * 100 );
			else if (mlx->map.map[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img5, j * 100, i * 100 );
			j++;
		}
		i++;
	}
}

void	init_mlx(t_mlx *mlx)
{
	if ((mlx->map.x * 100) > 2560)
		exit(0);
	if ((mlx->map.y * 100) > 1440)
		exit(0);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->map.x * 100, mlx->map.y * 100, "so_long");
	load_images(mlx);
	load_map(mlx);
}

void	setup(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L<<0, check_key, mlx);
	mlx_hook(mlx->win, 17, 1L<<2, exit_mlx, mlx);
	mlx_loop(mlx->mlx);
}

// void	a()
// {
// 	system("leaks so_long");
// }

void	parseo_term(int argc, char *argv)
{
	int i;

	i = ft_strlen(argv) - 4;
	if (argc != 2)
	{
		ft_printf("%s\n", "Numero de argumentos invalido");
		exit(0);
	}
	if (!ft_strchr(argv, '.'))
	{
		ft_printf("%s\n", "Mapa invalido");
		exit(0);
	}

	if (ft_strncmp(&argv[i], ".ber", 4))
	{
		ft_printf("%s\n", "Extension invalida");
		exit(0);
	}
}


int	main(int argc, char **argv)
{
	t_mlx	mlx;
	
	parseo_term(argc, argv[1]);
	open_map(argv[1], &mlx);
	init_mlx(&mlx);
	setup(&mlx);
	// atexit(a);
}