/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:01:51 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 11:48:59 by psoto-go         ###   ########.fr       */
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

typedef struct	map {
	char	**map;
	int		x;
	int		y;
	int		numcoll;
	
} t_map;

typedef struct	img {
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
} t_img;

typedef struct	mlx {
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	map;
	t_img	img;
} t_mlx;


void	open_map(char *argv, t_mlx *mlx);

void	ft_map_error();


#endif