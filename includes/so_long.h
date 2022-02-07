/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:01:51 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/07 18:12:11 by psoto-go         ###   ########.fr       */
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
// # include <mlx.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

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
	void	*i6;
	void	*i7;
	void	*i8;
	void	*i9;
	void	*i10;
}	t_img;

typedef struct player {
	int		x;
	int		y;
	int		moves;
	int		dir;
}	t_player;

typedef struct enemy {
	int		x;
	int		y;
	int		dir;
	int		time;
}	t_enemy;

typedef struct mlx {
	void		*mlx;
	void		*win;
	int			dir_coin;
	t_map		map;
	t_img		i;
	t_player	player;
	t_enemy		enemy;
}	t_mlx;

void	open_map(char *argv, t_mlx *mlx);

void	ft_error(int num, t_mlx *mlx);

void	load_map(t_mlx *mlx);

void	load_map2(t_mlx *m);

void	load_images(t_mlx *mlx);

void	parseo_term(int argc, char **argv, t_mlx *mlx);

void	init_mlx(t_mlx *mlx);

int		search_player(t_mlx *mlx);

int		check_key(int keycode, t_mlx *mlx);

int		keys(int keycode, t_mlx *mlx);

void	check_move(int k, t_mlx *mlx);

size_t	ft_strlen_ptr_ptr(char **s);

void	check_walls(char **map, t_mlx *mlx);

void	check_len_map(char **map, t_mlx *mlx);

void	check_collects(char **map, t_mlx *mlx);

void	check_num_collects2(int c, int e, int p, int z, t_mlx *mlx);

void	check_parser_map(char **map, t_mlx *mlx);

void	check_rectangle(char **map, t_mlx *mlx);

void	open_map(char *argv, t_mlx *mlx);

int		check_caca(int signo, char letra, t_mlx *mlx);

int	crear_cuadro(t_mlx *mlx);

int		ft_exit(int num, t_mlx *mlx);

int	check_time(t_mlx *mlx);

int	search_enemy(t_mlx *mlx);

void	a(void);


#endif