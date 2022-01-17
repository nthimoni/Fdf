/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoview.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:40:52 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 00:41:08 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "transfo.h"
#include "constantes.h"
#include "parse.h"
#include "colors.h"
#include "quit.h"

void	isoview(t_map *map)
{
	scale(0, map);
	free_map(map);
	parse_map(map, map->path);
	set_color(map);
	translate(- ((map->max.x - 1) * X_SC) / 2,
		- ((map->max.y - 1) * Y_SC) / 2, 0, map);
	rotate_x(M_PI / 8, map);
	rotate_y(-M_PI / 8, map);
	rotate_z(M_PI_4, map);
}

void	paraview(t_map *map)
{
	scale(0, map);
	free_map(map);
	parse_map(map, map->path);
	set_color(map);
	translate(- ((map->max.x - 1) * X_SC) / 2,
		- ((map->max.y - 1) * Y_SC) / 2, 0, map);
	rotate_x(M_PI_4, map);
	rotate_y(-M_PI_4, map);
	rotate_z(M_PI_4, map);
}
