/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:43:34 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/26 18:56:06 by psoto-go         ###   ########.fr       */
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

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 1000, "so_long");
	mlx->img = mlx_new_image(mlx->mlx, 1000, 1000);
	// mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length,
	// 							&mlx->endian);
	char	*relative_path = "/Users/psoto-go/Desktop/so_long/img/mar.xpm";
	int		img_width;
	int		img_height;

	mlx->img = mlx_xpm_file_to_image(mlx->mlx, relative_path, &img_width, &img_height);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	
	if (argc != 2)
	{
		ft_printf("%s\n", "Numero de argumentos invalido");
		exit(0);
	}
	if (!strchr(argv[1], '.'))
	{
		ft_printf("%s\n", "Mapa invalido");
		exit(0);
	}
	if (strcmp(strchr(argv[1], '.'), ".ber"))
	{
		ft_printf("%s\n", "Extension invalida");
		exit(0);
	}

	init_mlx(&mlx);



}