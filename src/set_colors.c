/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:27:07 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 00:22:15 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"
#include "constantes.h"

void	set_color(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->max.y)
	{
		j = 0;
		while (j < map->max.x)
		{
			if (map->map[i][j].z <= GROUND_MAX)
				map->map[i][j].color = GROUND_C;
			else if (map->map[i][j].z / Z_SC <= LVL_1_MAX)
				map->map[i][j].color = LVL_1_C;
			else
				map->map[i][j].color = LVL_2_C;
			j++;
		}
		i++;
	}
}

int	mix_color(int c1, int c2)
{
	return (mkcolor((get_t(c1) + get_t(c2)) / 2,
			(get_r(c1) + get_r(c2)) / 2,
			(get_g(c1) + get_g(c2)) / 2,
			(get_b(c1) + get_b(c2)) / 2));
}
