/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:48:56 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/03 00:35:50 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_key(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		ft_exit(0, mlx);
	return (0);
}

void	ft_delete(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->i.i1);
	mlx_destroy_image(mlx->mlx, mlx->i.i2);
	mlx_destroy_image(mlx->mlx, mlx->i.i3);
	mlx_destroy_image(mlx->mlx, mlx->i.i4);
	mlx_destroy_image(mlx->mlx, mlx->i.i5);
	mlx_destroy_image(mlx->mlx, mlx->i.i6);
	mlx_destroy_image(mlx->mlx, mlx->i.i7);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
}

void	free_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map.map[i])
	{
		free(mlx->map.map[i]);
		i++;
	}
	free(mlx->map.map);
}


int	ft_exit(int num, t_mlx *mlx)
{
	if (num == 1)
		ft_printf("Has perdido!\n");
	if (num == 2)
		ft_printf("Has Ganado!\n");
	if (mlx->map.map)
		free_map(mlx);
	if (mlx->mlx)
		ft_delete(mlx);
	// a();

	exit(0);
	return(0);
}
