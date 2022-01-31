/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:57:41 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 18:51:51 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parseo_term(int argc, char *argv)
{
	int	i;

	i = ft_strlen(argv) - 4;
	if (argc != 2)
		ft_error(2);
	if (!ft_strchr(argv, '.'))
		ft_error(3);
	if (ft_strncmp(&argv[i], ".ber", 4))
		ft_error(4);
}
