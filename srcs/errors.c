/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:44:26 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/02 23:52:28 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(int num, t_mlx *mlx)
{
	if (num == 1)
		ft_printf("%s\n", "Error de lectura en el mapa");
	else if (num == 2)
		ft_printf("Error: %s\n", "Numero de argumentos invalido");
	else if (num == 3)
		ft_printf("Error: %s\n", "Mapa sin extension");
	else if (num == 4)
		ft_printf("Error: %s\n", "Extension invalida");
	else if (num == 5)
		ft_printf("Error: %s\n", "Hay un salto de linea en el mapa");
	else if (num == 6)
		ft_printf("Error: %s\n", "No hay la misma longitud en todas las filas");
	else if (num == 7)
		ft_printf("Error: %s\n", "El mapa no es rectangular");
	else if (num == 8)
		ft_printf("Error: %s\n", "El mapa no esta cerrado por muros");
	else if (num == 9)
		ft_printf("Error: %s\n", "El mapa tiene un caracter no permitido");
	ft_exit(0, mlx);
}
