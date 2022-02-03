/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:57:41 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/03 00:54:12 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parseo_term(int argc, char **argv, t_mlx *mlx)
{
	int	i;

	if (argc != 2)
		ft_error(2, mlx);
	if (!ft_strchr(argv[1], '.'))
		ft_error(3, mlx);
	i = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(&argv[1][i], ".ber", 4))
		ft_error(4, mlx);
}
