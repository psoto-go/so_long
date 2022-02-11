/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:06:46 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/09 12:21:19 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_move_right_enemy(t_mlx *mlx)
{
	if (mlx->map.map[mlx->enemy.x][mlx->enemy.y + 1] == 'P')
		ft_exit(1, mlx);
	if (mlx->map.map[mlx->enemy.x][mlx->enemy.y + 1] == '0'
		&& mlx->enemy.dir == 0)
	{
		mlx->map.map[mlx->enemy.x][mlx->enemy.y + 1] = 'Z';
		mlx->map.map[mlx->enemy.x][mlx->enemy.y] = '0';
		mlx->enemy.y = mlx->enemy.y + 1;
	}
	else
		mlx->enemy.dir = rand() % 4;
	load_map(mlx);
}

void	check_move_left_enemy(t_mlx *mlx)
{
	if (mlx->map.map[mlx->enemy.x][mlx->enemy.y - 1] == 'P')
		ft_exit(1, mlx);
	if (mlx->map.map[mlx->enemy.x][mlx->enemy.y - 1] == '0'
		&& mlx->enemy.dir == 1)
	{
		mlx->map.map[mlx->enemy.x][mlx->enemy.y - 1] = 'Z';
		mlx->map.map[mlx->enemy.x][mlx->enemy.y] = '0';
		mlx->enemy.y = mlx->enemy.y - 1;
	}
	else
		mlx->enemy.dir = rand() % 4;
	load_map(mlx);
}

void	check_move_down_enemy(t_mlx *mlx)
{
	if (mlx->map.map[mlx->enemy.x + 1][mlx->enemy.y] == 'P')
		ft_exit(1, mlx);
	if (mlx->map.map[mlx->enemy.x + 1][mlx->enemy.y] == '0'
		&& mlx->enemy.dir == 3)
	{
		mlx->map.map[mlx->enemy.x + 1][mlx->enemy.y] = 'Z';
		mlx->map.map[mlx->enemy.x][mlx->enemy.y] = '0';
		mlx->enemy.x = mlx->enemy.x + 1;
	}
	else
		mlx->enemy.dir = rand() % 4;
	load_map(mlx);
}

void	check_move_top_enemy(t_mlx *mlx)
{
	if (mlx->map.map[mlx->enemy.x - 1][mlx->enemy.y] == 'P')
		ft_exit(1, mlx);
	if (mlx->map.map[mlx->enemy.x - 1][mlx->enemy.y] == '0'
		&& mlx->enemy.dir == 2)
	{
		mlx->map.map[mlx->enemy.x - 1][mlx->enemy.y] = 'Z';
		mlx->map.map[mlx->enemy.x][mlx->enemy.y] = '0';
		mlx->enemy.x = mlx->enemy.x - 1;
	}
	else
		mlx->enemy.dir = rand() % 4;
	load_map(mlx);
}

int	check_time(t_mlx *mlx)
{
	mlx->enemy.time++;
	if (mlx->enemy.time % 4000 == 0)
	{
		mlx->enemy.dir = rand() % 4;
		if (mlx->enemy.dir == 0)
			check_move_right_enemy(mlx);
		else if (mlx->enemy.dir == 1)
			check_move_left_enemy(mlx);
		else if (mlx->enemy.dir == 2)
			check_move_top_enemy(mlx);
		else if (mlx->enemy.dir == 3)
			check_move_down_enemy(mlx);
	}
	if (mlx->enemy.time % 2300 == 0)
		mlx->dir_coin = 1;
	if (mlx->enemy.time % 5237 == 0)
		mlx->dir_coin = 0;
	return (0);
}
