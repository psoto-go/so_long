/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:43:34 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/03 16:52:20 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	a(void)
{
	system("leaks so_long");
}

void	setup(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, check_key, mlx);
	mlx_hook(mlx->win, 17, 1L << 2, ft_exit, mlx);
	search_player(mlx);
	search_enemy(mlx);
	mlx_loop_hook(mlx->mlx, check_time , mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_loop(mlx->mlx);
}

void	init_values(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->i.i1 = NULL;
	mlx->i.i2= NULL;
	mlx->i.i3 = NULL;
	mlx->i.i4 = NULL;
	mlx->i.i5 = NULL;
	mlx->i.i6 = NULL;
	mlx->i.i7 = NULL;
	mlx->i.i8 = NULL;
	mlx->i.i9 = NULL;
	mlx->i.i10 = NULL;
	mlx->map.map = NULL;
	mlx->map.numcoll = 0;
	mlx->map.x = 0;
	mlx->map.y = 0;
	mlx->player.moves = 0;
	mlx->player.x = 0;
	mlx->player.y = 0;
	mlx->player.dir = 0;
	mlx->enemy.x = 0;
	mlx->enemy.y = 0;
	mlx->enemy.dir = 0;
	mlx->enemy.time = 0;
	mlx->dir_coin = 0;

}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	init_values(&mlx);
	parseo_term(argc, argv, &mlx);
	open_map(argv[1], &mlx);
	init_mlx(&mlx);
	setup(&mlx);
	return (0);
}
