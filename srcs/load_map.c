/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:46:22 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/11 19:52:05 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_p(t_mlx *m, int j, int i, int n)
{
	mlx_put_image_to_window(m->mlx, m->win, m->i.i2, j * n, i * n);
	if (m->player.dir == 0)
		mlx_put_image_to_window(m->mlx, m->win, m->i.i5,
			(j - 0.2) * n, (i - 0.04) * n);
	else
		mlx_put_image_to_window(m->mlx, m->win, m->i.i7,
			(j - 0.2) * n, (i - 0.04) * n);
}

void	print_c(t_mlx *m, int j, int i, int n)
{
	mlx_put_image_to_window(m->mlx, m->win, m->i.i2, j * n, i * n);
	if (m->dir_coin == 0)
		mlx_put_image_to_window(m->mlx, m->win, m->i.i3,
			j * n, i * n);
	else
		mlx_put_image_to_window(m->mlx, m->win, m->i.i10,
			j * n, i * n);
}

void	print_e(t_mlx *m, int j, int i, int n)
{
	mlx_put_image_to_window(m->mlx, m->win, m->i.i2, j * n, i * n);
	mlx_put_image_to_window(m->mlx, m->win, m->i.i4,
		(j - 0.15) * n, (i - 0.2) * n);
}
