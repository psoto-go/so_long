/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:44:26 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 19:48:42 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(int num)
{
	if (num == 1)
		ft_printf("%s\n", "Error de mapa");
	else if (num == 2)
		ft_printf("%s\n", "Numero de argumentos invalido");
	else if (num == 3)
		ft_printf("%s\n", "Mapa invalido");
	else if (num == 4)
		ft_printf("%s\n", "Extension invalida");
	exit(0);
}

// void	ft_exit(int num);