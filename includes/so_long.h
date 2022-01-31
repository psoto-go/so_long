/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:01:51 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 13:51:40 by psoto-go         ###   ########.fr       */
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
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
}	t_img;

typedef struct player {
	int		x;
	int		y;
}	t_player;

typedef struct mlx {
	void		*mlx;
	void		*win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		map;
	t_img		img;
	t_player	player;
}	t_mlx;

void	open_map(char *argv, t_mlx *mlx);

void	ft_map_error(void);

void	load_map(t_mlx *mlx);

void	load_images(t_mlx *mlx);

void	parseo_term(int argc, char *argv);

void	init_mlx(t_mlx *mlx);

int		search_player(t_mlx *mlx);

int		check_key(int keycode, t_mlx *mlx);

int		exit_mlx(t_mlx *mlx);

#endif