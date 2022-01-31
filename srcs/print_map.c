/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:55:37 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 17:48:18 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_mlx *m)
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
	m->i.i1 = mlx_xpm_file_to_image(m->mlx, p1, &m->map.x, &m->map.y);
	m->i.i2 = mlx_xpm_file_to_image(m->mlx, p0, &m->map.x, &m->map.y);
	m->i.i3 = mlx_xpm_file_to_image(m->mlx, c, &m->map.x, &m->map.y);
	m->i.i4 = mlx_xpm_file_to_image(m->mlx, e, &m->map.x, &m->map.y);
	m->i.i5 = mlx_xpm_file_to_image(m->mlx, p, &m->map.x, &m->map.y);
}

void	load_map(t_mlx *m)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 100;
	while (m->map.map[i])
	{
		j = 0;
		while (m->map.map[i][j])
		{
			if (m->map.map[i][j] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->i.i1, j * n, i * n);
			else if (m->map.map[i][j] == '0')
				mlx_put_image_to_window(m->mlx, m->win, m->i.i2, j * n, i * n);
			else if (m->map.map[i][j] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->i.i3, j * n, i * n);
			else if (m->map.map[i][j] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->i.i4, j * n, i * n);
			else if (m->map.map[i][j] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->i.i5, j * n, i * n);
			j++;
		}
		i++;
	}
}

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
