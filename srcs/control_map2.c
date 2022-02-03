/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:27:29 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/03 01:05:50 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen_ptr_ptr(char **s)
{
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = 0;
	while (s[count] != (void *)0)
	{
		count2 = 0;
		while (s[count][count2] != '\0')
			count2++;
		count++;
	}
	return (count);
}

void	check_walls(char **map, t_mlx *mlx)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[0][i] != '1' || map[ft_strlen_ptr_ptr(map) - 1][i] != '1' )
				ft_error(8, mlx);
			i++;
		}
		i = 0;
		while (map[i])
		{
			if (map[i][0] != '1' || map[i][ft_strlen(*map) - 1] != '1' )
				ft_error(8, mlx);
			i++;
		}
		j++;
	}
}

void	check_len_map(char **map, t_mlx *mlx)
{
	int		i;
	size_t	len;
	int		flag;

	i = 0;
	flag = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			ft_error(6, mlx);
		i++;
	}
}

void	check_collects(char **map, t_mlx *mlx)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
			&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'M'
			&& map[i][j] != 'Z')
				ft_error(9, mlx);
			j++;
		}
		i++;
	}
}

void	check_num_collects2(int c, int e, int p, t_mlx *mlx)
{
	if (c == 0 || e == 0 || p != 1)
		ft_error(10, mlx);
	if (c != 0)
		mlx->map.numcoll = c;
}
