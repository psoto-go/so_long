/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:03:17 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 13:47:28 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	search_player(t_mlx *mlx)
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
			if (mlx->map.map[i][j] == 'P')
			{
				mlx->player.x = i;
				mlx->player.y = j;
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
