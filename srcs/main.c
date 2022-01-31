/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:43:34 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 13:49:42 by psoto-go         ###   ########.fr       */
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

void	setup(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L<<0, check_key, mlx);
	mlx_hook(mlx->win, 17, 1L<<2, exit_mlx, mlx);
	search_player(mlx);
	mlx_loop(mlx->mlx);
}

// void	a()
// {
// 	system("leaks so_long");
// }

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	
	parseo_term(argc, argv[1]);
	open_map(argv[1], &mlx);
	init_mlx(&mlx);
	setup(&mlx);
	// atexit(a);
}