/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:55:37 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 12:56:17 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_mlx *mlx)
{
	char	*p1;
	char	*p0;
	char	*c;
	char	*e;
	char	*p;

	p1 = "img/cubo.xpm";
	p0 = "img/cesped.xpm";
	c = "img/surf.xpm";
	e = "img/mar.xpm";
	p = "img/mario.xpm";

	mlx->img.img1 = mlx_xpm_file_to_image(mlx->mlx, p1, &mlx->map.x, &mlx->map.y);
	mlx->img.img2 = mlx_xpm_file_to_image(mlx->mlx, p0, &mlx->map.x, &mlx->map.y);
	mlx->img.img3 = mlx_xpm_file_to_image(mlx->mlx, c, &mlx->map.x, &mlx->map.y);
	mlx->img.img4 = mlx_xpm_file_to_image(mlx->mlx, e, &mlx->map.x, &mlx->map.y);
	mlx->img.img5 = mlx_xpm_file_to_image(mlx->mlx, p, &mlx->map.x, &mlx->map.y);
}

void	load_map(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	while (mlx->map.map[i])
	{
		j = 0;
		while(mlx->map.map[i][j])
		{
			if (mlx->map.map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img1, j * 100, i * 100 );
			else if (mlx->map.map[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img2, j * 100, i * 100 );
			else if (mlx->map.map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img3, j * 100, i * 100 );
			else if (mlx->map.map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img4, j * 100, i * 100 );
			else if (mlx->map.map[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img5, j * 100, i * 100 );
			j++;
		}
		i++;
	}
}