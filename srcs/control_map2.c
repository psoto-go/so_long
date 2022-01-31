/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:27:29 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 20:03:58 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen_ptr_ptr(char **s)
{
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = 0;
	while (s[count] != '\0')
	{
		count2 = 0;
		while (s[count][count2] != '\0')
			count2++;
		count++;
	}
	return (count);
}

int	check_walls(char **map)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[0][i] != '1' || map[ft_strlen_ptr_ptr(map) - 1][i] != '1' )
				flag = 1;
			i++;
		}
		i = 0;
		while (map[i])
		{
			if (map[i][0] != '1' || map[i][ft_strlen(*map) - 1] != '1' )
				flag = 1;
			i++;
		}
		j++;
	}
	return (flag);
}

int	check_len_map(char **map)
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
			flag = 1;
		i++;
	}
	return (flag);
}

int	check_collects(char **map)
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
			&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'M')
				flag = 1;
			j++;
		}
		i++;
	}
	return (flag);
}

int	check_num_collects2(int c, int e, int p, t_mlx *mlx)
{
	int	flag;

	flag = 0;
	if (c == 0 || e == 0 || p != 1)
		flag = 1;
	if (c != 0)
		mlx->map.numcoll = c;
	return (flag);
}
