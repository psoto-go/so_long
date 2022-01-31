/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:57:41 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/31 13:00:04 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parseo_term(int argc, char *argv)
{
	int i;

	i = ft_strlen(argv) - 4;
	if (argc != 2)
	{
		ft_printf("%s\n", "Numero de argumentos invalido");
		exit(0);
	}
	if (!ft_strchr(argv, '.'))
	{
		ft_printf("%s\n", "Mapa invalido");
		exit(0);
	}

	if (ft_strncmp(&argv[i], ".ber", 4))
	{
		ft_printf("%s\n", "Extension invalida");
		exit(0);
	}
}