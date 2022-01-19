/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:27:07 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/19 15:27:41 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"
#include "constantes.h"
#include "libft.h"
#include "stdio.h"

int	mix_color(int c1, int c2, float f)
{
	return (mkcolor(get_t(c1) * f + get_t(c2) * (1 - f),
			get_r(c1) * f + get_r(c2) * (1 - f),
			get_g(c1) * f + get_g(c2) * (1 - f),
			get_b(c1) * f + get_b(c2) * (1 - f)));
}
