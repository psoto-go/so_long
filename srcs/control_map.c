/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:09:45 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 17:56:07 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_num_collects(char **map, t_mlx *mlx)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c += 1;
			else if (map[i][j] == 'E')
				e += 1;
			else if (map[i][j] == 'P')
				p += 1;
			j++;
		}
	}
	return (check_num_collects2(c, e, p, mlx));
}

int	check_rectangle(char **map)
{
	int	flag;

	flag = 0;
	if (ft_strlen(*map) == ft_strlen_ptr_ptr(map))
		flag = 1;
	return (flag);
}

int	check_parser_map(char **map, t_mlx *mlx)
{
	int	flag;

	flag = 0;
	flag += check_len_map(map);
	flag += check_rectangle(map);
	flag += check_walls(map);
	flag += check_collects(map);
	flag += check_num_collects(map, mlx);
	return (flag);
}

void	open_map(char *argv, t_mlx *mlx)
{
	int		file;
	char	*line;
	char	*str;
	char	**map;

	file = open(argv, O_RDONLY);
	str = ft_calloc(1, 1);
	line = get_next_line(file);
	while (line)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(file);
	}
	free(line);
	map = ft_split(str, '\n');
	if (!*map)
		ft_error(1);
	free(str);
	if (check_parser_map(map, mlx) == 0)
	{
		mlx->map.map = map;
		mlx->map.x = ft_strlen(*map);
		mlx->map.y = ft_strlen_ptr_ptr(map);
	}
	else
		ft_error(1);
}
