/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:20:02 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/12 10:50:25 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keys(int k, t_mlx *mlx)
{
	int	c;

	c = 0;
	if ((k >= 123 && k <= 126) || (k >= 0 && k <= 2) || (k == 13))
	{
		c = mlx->player.moves;
		check_move(k, mlx);
		if (mlx->player.moves != c)
		{
			ft_printf("Numero de movimientos: %d \n", mlx->player.moves);
			c = mlx->player.moves;
		}
	}
	return (0);
}
