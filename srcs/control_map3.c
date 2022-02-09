/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:38:25 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/09 12:40:40 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_num_collects2(int p, int z, t_mlx *mlx)
{
	if (p != 1)
		ft_error(12, mlx);
	if (z != 1)
		ft_error(13, mlx);
}

void	check_num_collects3(int c, int e, t_mlx *mlx)
{
	if (c == 0)
		ft_error(10, mlx);
	if (e == 0)
		ft_error(11, mlx);
	if (c != 0)
		mlx->map.numcoll = c;
}

void	check_num_collects_check(char **map, t_mlx *mlx)
{
	int	i;
	int	j;
	int	p;
	int	z;

	i = 0;
	p = 0;
	z = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p += 1;
			else if (map[i][j] == 'Z')
				z += 1;
			j++;
		}
	}
	check_num_collects2(p, z, mlx);
}

void	check_num_collects(char **map, t_mlx *mlx)
{
	int	i;
	int	j;
	int	c;
	int	e;

	i = 0;
	c = 0;
	e = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c += 1;
			else if (map[i][j] == 'E')
				e += 1;
			j++;
		}
	}
	check_num_collects3(c, e, mlx);
	check_num_collects_check(map, mlx);
}
