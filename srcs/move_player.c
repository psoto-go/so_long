/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:03:17 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 19:20:35 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_move_up(t_mlx *mlx)
{
	int	c;

	c = 0;
	if (mlx->map.map[mlx->player.x - 1][mlx->player.y] == 'E')
		c = 1;
	if (mlx->map.map[mlx->player.x - 1][mlx->player.y] != '1')
	{
		if (mlx->map.map[mlx->player.x - 1][mlx->player.y] == 'C')
			mlx->map.numcoll--;
		if (mlx->map.map[mlx->player.x - 1][mlx->player.y] == 'E' &&
		mlx->map.numcoll != 0)
			return ;
		if (check_caca(1, 'x', mlx) == 1)
		{
			mlx->player.moves += 1;
			exit_mlx(mlx);
		}
		else
		{
			mlx->map.map[mlx->player.x - 1][mlx->player.y] = 'P';
			mlx->map.map[mlx->player.x][mlx->player.y] = '0';
			mlx->player.x = mlx->player.x - 1;
			if ((c == 1 && mlx->map.numcoll == 0))
				exit_mlx(mlx);
			mlx->player.moves += 1;
		}
		load_map(mlx);
	}
}

void	check_move_down(t_mlx *mlx)
{
	int	c;

	c = 0;
	if (mlx->map.map[mlx->player.x + 1][mlx->player.y] == 'E')
		c = 1;
	if (mlx->map.map[mlx->player.x + 1][mlx->player.y] != '1')
	{
		if (mlx->map.map[mlx->player.x + 1][mlx->player.y] == 'C')
			mlx->map.numcoll--;
		if (mlx->map.map[mlx->player.x + 1][mlx->player.y] == 'E' &&
		mlx->map.numcoll != 0)
			return ;
		if (check_caca(0, 'x', mlx) == 1)
		{
			mlx->player.moves += 1;
			exit_mlx(mlx);
		}
		else
		{
			mlx->map.map[mlx->player.x + 1][mlx->player.y] = 'P';
			mlx->map.map[mlx->player.x][mlx->player.y] = '0';
			mlx->player.x = mlx->player.x + 1;
			if ((c == 1 && mlx->map.numcoll == 0))
				exit_mlx(mlx);
			mlx->player.moves += 1;
			
		}
		load_map(mlx);
	}
}

void	check_move_right(t_mlx *mlx)
{
	int	c;

	c = 0;
	if (mlx->map.map[mlx->player.x][mlx->player.y + 1] == 'E')
		c = 1;
	if (mlx->map.map[mlx->player.x][mlx->player.y + 1] != '1')
	{
		if (mlx->map.map[mlx->player.x][mlx->player.y + 1] == 'C')
			mlx->map.numcoll--;
		if (mlx->map.map[mlx->player.x][mlx->player.y + 1] == 'E' &&
		mlx->map.numcoll != 0)
			return ;
		if (check_caca(0, 'y', mlx) == 1)
		{
			mlx->player.moves += 1;
			exit_mlx(mlx);
		}
		else
		{
			mlx->map.map[mlx->player.x][mlx->player.y + 1] = 'P';
			mlx->map.map[mlx->player.x][mlx->player.y] = '0';
			mlx->player.y = mlx->player.y + 1;
			if ((c == 1 && mlx->map.numcoll == 0))
				exit_mlx(mlx);
			mlx->player.moves += 1;
			
		}
		load_map(mlx);
	}
}

void	check_move_left(t_mlx *mlx)
{
	int	c;

	c = 0;
	if (mlx->map.map[mlx->player.x][mlx->player.y - 1] == 'E')
		c = 1;
	if (mlx->map.map[mlx->player.x][mlx->player.y - 1] != '1')
	{
		if (mlx->map.map[mlx->player.x][mlx->player.y - 1] == 'C')
			mlx->map.numcoll--;
		if (mlx->map.map[mlx->player.x][mlx->player.y - 1] == 'E' &&
		mlx->map.numcoll != 0)
			return ;
		if (check_caca(1, 'y', mlx) == 1)
		{
			mlx->player.moves += 1;
			exit_mlx(mlx);
		}
		else
		{
			mlx->map.map[mlx->player.x][mlx->player.y - 1] = 'P';
			mlx->map.map[mlx->player.x][mlx->player.y] = '0';
			mlx->player.y = mlx->player.y - 1;
			if ((c == 1 && mlx->map.numcoll == 0))
				exit_mlx(mlx);
			mlx->player.moves += 1;
		}
		load_map(mlx);
	}
}

void	check_move(int k, t_mlx *mlx)
{
	if (k == 126 || k == 13)
		check_move_up(mlx);
	else if (k == 125 || k == 1)
		check_move_down(mlx);
	else if (k == 124 || k == 2)
		check_move_right(mlx);
	else if (k == 123 || k == 0)
		check_move_left(mlx);
}
