/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:20:02 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 17:37:43 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keys(int k, t_mlx *mlx)
{
	if ((k >= 123 && k <= 126) || (k >= 0 && k <= 2) || (k == 13))
	{
		check_move(k, mlx);
		mlx->player.moves += 1;
		ft_printf("Numero de movimientos: %d \n", mlx->player.moves);
	}
	return (0);
}
