/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:00:56 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 13:01:14 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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