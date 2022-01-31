/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:43:34 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 18:03:37 by psoto-go         ###   ########.fr       */
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
	mlx_hook(mlx->win, 17, 1L << 2, exit_mlx, mlx);
	search_player(mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	parseo_term(argc, argv[1]);
	open_map(argv[1], &mlx);
	init_mlx(&mlx);
	setup(&mlx);
}
