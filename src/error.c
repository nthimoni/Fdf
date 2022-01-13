/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:13:52 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/13 01:17:19 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"

int	error_msg(int code)
{
	if (code == 0)
		return (1);
	if (code == INV_ARG)
		ft_printf("Invalid argument !\n");
	else if (code == BAD_ALLOC)
		ft_printf("Erreur lors de l'allocation de la memoire !\n");
	else if (code == MAP_FORMAT)
		ft_printf("Le format du fichier map n'est pas standard !\n");
	return (0);
}
