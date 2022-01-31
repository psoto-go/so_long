/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:55:37 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 19:12:23 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_mlx *m)
{
	m->i.i1 = "img/cubo.xpm";
	m->i.i2 = "img/cesped.xpm";
	m->i.i3 = "img/surf.xpm";
	m->i.i4 = "img/mar.xpm";
	m->i.i5 = "img/mario.xpm";
	m->i.i6 = "img/caca.xpm";
	m->i.i1 = mlx_xpm_file_to_image(m->mlx, m->i.i1, &m->map.x, &m->map.y);
	m->i.i2 = mlx_xpm_file_to_image(m->mlx, m->i.i2, &m->map.x, &m->map.y);
	m->i.i3 = mlx_xpm_file_to_image(m->mlx, m->i.i3, &m->map.x, &m->map.y);
	m->i.i4 = mlx_xpm_file_to_image(m->mlx, m->i.i4, &m->map.x, &m->map.y);
	m->i.i5 = mlx_xpm_file_to_image(m->mlx, m->i.i5, &m->map.x, &m->map.y);
	m->i.i6 = mlx_xpm_file_to_image(m->mlx, m->i.i6, &m->map.x, &m->map.y);
}

void	load_map2(t_mlx *m)
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
			if (m->map.map[i][j] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->i.i5, j * n, i * n);
			else if (m->map.map[i][j] == 'M')
				mlx_put_image_to_window(m->mlx, m->win, m->i.i6, j * n, i * n);
			j++;
		}
		i++;
	}
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
			j++;
		}
		i++;
	}
	load_map2(m);
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

int	check_caca(int signo, char letra, t_mlx *mlx)
{
	if (signo == 1 && letra == 'x')
	{
		if (mlx->map.map[mlx->player.x - 1][mlx->player.y] == 'M')
			return (1);
	}
	else if (signo == 0 && letra == 'x')
	{
		if (mlx->map.map[mlx->player.x + 1][mlx->player.y] == 'M')
			return (1);
	}
	else if (signo == 1 && letra == 'y')
	{
		if (mlx->map.map[mlx->player.x][mlx->player.y - 1] == 'M')
			return (1);
	}
	else if (signo == 0 && letra == 'y')
	{
		if (mlx->map.map[mlx->player.x][mlx->player.y + 1] == 'M')
			return (1);
	}
	return (0);
}
