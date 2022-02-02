/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:06:46 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/02 21:47:19 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	search_enemy(t_mlx *mlx)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (mlx->map.map)
	{
		j = 0;
		while (mlx->map.map[i][j])
		{
			if (mlx->map.map[i][j] == 'C')
			{
				mlx->enemy.x = i;
				mlx->enemy.y = j;
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 1)
			break ;
		i++;
	}
	return (flag);
}

void	check_move_right_enemy(t_mlx *mlx)
{
	if (mlx->map.map[mlx->enemy.x][mlx->enemy.y + 1] == '0')
	{
		mlx->map.map[mlx->enemy.x][mlx->enemy.y + 1] = 'C';
		mlx->map.map[mlx->enemy.x][mlx->enemy.y] = '0';
		mlx->enemy.y = mlx->enemy.y + 1;
	}
		load_map(mlx);
}
