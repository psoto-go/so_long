/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:09:45 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/02 23:44:07 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_num_collects(char **map, t_mlx *mlx)
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
	check_num_collects2(c, e, p, mlx);
}

void	check_rectangle(char **map, t_mlx *mlx)
{
	if (ft_strlen(*map) == ft_strlen_ptr_ptr(map))
		ft_error(7, mlx);
}

void	check_parser_map(char **map, t_mlx *mlx)
{
	check_len_map(map, mlx);
	check_rectangle(map, mlx);
	check_walls(map, mlx);
	check_collects(map, mlx);
	check_num_collects(map, mlx);
}

void	check_salto(char *str, t_mlx *mlx)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			ft_error(5, mlx);
		}
		i++;
	}
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
	check_salto(str, mlx);
	map = ft_split(str, '\n');
	if (!*map)
		ft_error(1, mlx);
	free(str);
	check_parser_map(map, mlx);
	mlx->map.map = map;
	mlx->map.x = ft_strlen(*map);
	mlx->map.y = ft_strlen_ptr_ptr(map);
}
