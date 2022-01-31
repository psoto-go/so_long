/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:01:51 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 18:02:35 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct map {
	char	**map;
	int		x;
	int		y;
	int		numcoll;
}	t_map;

typedef struct img {
	void	*i1;
	void	*i2;
	void	*i3;
	void	*i4;
	void	*i5;
}	t_img;

typedef struct player {
	int		x;
	int		y;
	int		moves;
}	t_player;

typedef struct mlx {
	void		*mlx;
	void		*win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		map;
	t_img		i;
	t_player	player;
}	t_mlx;

void	open_map(char *argv, t_mlx *mlx);

void	ft_error(int num);

void	load_map(t_mlx *mlx);

void	load_images(t_mlx *mlx);

void	parseo_term(int argc, char *argv);

void	init_mlx(t_mlx *mlx);

int		search_player(t_mlx *mlx);

int		check_key(int keycode, t_mlx *mlx);

int		exit_mlx(t_mlx *mlx);

int		keys(int keycode, t_mlx *mlx);

void	check_move(int k, t_mlx *mlx);

size_t	ft_strlen_ptr_ptr(char **s);

int		check_walls(char **map);

int		check_len_map(char **map);

int		check_collects(char **map);

int		check_num_collects2(int c, int e, int p, t_mlx *mlx);

int		check_parser_map(char **map, t_mlx *mlx);

int		check_rectangle(char **map);

int		check_num_collects(char **map, t_mlx *mlx);

void	open_map(char *argv, t_mlx *mlx);
void	a(void);



#endif