/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:09:45 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/28 18:27:26 by psoto-go         ###   ########.fr       */
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
			&& map[i][j] != 'E' && map[i][j] != 'P')
				flag = 1;
			j++;
		}
		i++;
	}
	return (flag);
}

int	check_num_collects2(int c, int e, int p)
{
	int flag;

	flag = 0;
	if (c == 0 || e == 0 || p != 1)
		flag = 1;
	return (flag);
}

int	check_num_collects(char **map)
{
	int	i;
	int	j;
	int c;
	int e;
	int p;

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
	return (check_num_collects2(c, e, p));
}

int check_rectangle(char **map)
{
	int flag;

	flag = 0;
	if (ft_strlen(*map) == ft_strlen_ptr_ptr(map))
		flag = 1;
	return (flag);
}

int	check_parser_map(char **map)
{
	int	flag;

	flag = 0;
	flag += check_len_map(map);
	flag += check_rectangle(map);
	flag += check_walls(map);
	flag += check_collects(map);
	flag += check_num_collects(map);
	return (flag);
}

void	open_map(char *argv, t_mlx *mlx)
{
	int		file;
	char	*line;
	char	*str;
	char	**map;

	file = open(argv, O_RDONLY);
	str = calloc(1, 1);
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
		ft_map_error();
	free(str);
	if (check_parser_map(map) == 0)
	{
		mlx->map.map = map;
		mlx->map.x = ft_strlen(*map);
		mlx->map.y = ft_strlen_ptr_ptr(map);
	}
	else
		ft_map_error();
}
