/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:00:56 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/02 22:32:09 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(t_mlx *m)
{
	if ((m->map.x * 100) > 2560)
		exit(0);
	if ((m->map.y * 100) > 1440)
		exit(0);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->map.x * 100, m->map.y * 100, "so_long");
	load_images(m);
	load_map(m);
}
