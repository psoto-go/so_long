/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:48:56 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 13:49:17 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		exit_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return(0);
}

int 	check_key(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit_mlx(mlx);
	return (0);
}
