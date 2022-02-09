/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:14:38 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/09 12:16:20 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_p2(t_mlx *mlx, int flag, int sim)
{
	if (flag == 0 && sim == 1)
	{
		mlx->player.dir = 0;
		mlx->map.map[mlx->player.x][mlx->player.y + 1] = 'P';
		mlx->map.map[mlx->player.x][mlx->player.y] = '0';
		mlx->player.y = mlx->player.y + 1;
	}
	if (flag == 0 && sim == 0)
	{
		mlx->player.dir = 1;
		mlx->map.map[mlx->player.x][mlx->player.y - 1] = 'P';
		mlx->map.map[mlx->player.x][mlx->player.y] = '0';
		mlx->player.y = mlx->player.y - 1;
	}
	mlx->player.moves += 1;
}

void	change_p(t_mlx *mlx, int flag, int sim)
{
	if (flag == 1 && sim == 0)
	{
		mlx->map.map[mlx->player.x - 1][mlx->player.y] = 'P';
		mlx->map.map[mlx->player.x][mlx->player.y] = '0';
		mlx->player.x = mlx->player.x - 1;
	}
	if (flag == 1 && sim == 1)
	{
		mlx->map.map[mlx->player.x + 1][mlx->player.y] = 'P';
		mlx->map.map[mlx->player.x][mlx->player.y] = '0';
		mlx->player.x = mlx->player.x + 1;
	}
	change_p2 (mlx, flag, sim);
}
