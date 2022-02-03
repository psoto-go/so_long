/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:20:02 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/03 02:51:25 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	crear_cuadro(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 30)
	{
		j=0;
		while (j <= 260)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

int	keys(int k, t_mlx *mlx)
{
	char *c;

	c = ft_itoa(mlx->player.moves);
	if ((k >= 123 && k <= 126) || (k >= 0 && k <= 2) || (k == 13))
	{
		check_move(k, mlx);
		crear_cuadro(mlx);
		mlx_string_put(mlx->mlx, mlx->win, 1, 3,0xFFFFFF, "Numero de movimientos: ");
		mlx_string_put(mlx->mlx, mlx->win, 220, 3,0xFFFFFF, c);
	}
	free(c);
	return (0);
}
