/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:06:11 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 00:39:25 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "constantes.h"
#include <math.h>
#include <stdio.h>

void	translate(int tx, int ty, int tz, t_map *map)
{
	int	i;
	int	u;

	i = 0;
	while (i < map->max.y)
	{
		u = 0;
		while (u < map->max.x)
		{
			map->map[i][u].x += tx;
			map->map[i][u].y += ty;
			map->map[i][u].z += tz;
			u++;
		}
		i++;
	}
}

void	rotate_x(float tx, t_map *map)
{
	int				i;
	int				u;
	float			y;
	float			z;

	i = 0;
	while (i < map->max.y)
	{
		u = 0;
		while (u < map->max.x)
		{
			y = map->map[i][u].y;
			z = map->map[i][u].z;
			map->map[i][u].y = (cos(tx) * y) - (sin(tx) * z);
			map->map[i][u].z = (sin(tx) * y) + (cos(tx) * z);
			u++;
		}
		i++;
	}
}

void	rotate_z(float tz, t_map *map)
{
	int				i;
	int				u;
	float			x;
	float			y;

	i = 0;
	while (i < map->max.y)
	{
		u = 0;
		while (u < map->max.x)
		{
			y = map->map[i][u].y;
			x = map->map[i][u].x;
			map->map[i][u].x = (cos(tz) * x) - (sin(tz) * y);
			map->map[i][u].y = (sin(tz) * x) + (cos(tz) * y);
			u++;
		}
		i++;
	}
}

void	rotate_y(float ty, t_map *map)
{
	int				i;
	int				u;
	float			x;
	float			z;

	i = 0;
	while (i < map->max.y)
	{
		u = 0;
		while (u < map->max.x)
		{
			z = map->map[i][u].z;
			x = map->map[i][u].x;
			map->map[i][u].x = (cos(ty) * x) + (sin(ty) * z);
			map->map[i][u].z = - (sin(ty) * x) + (cos(ty) * z);
			u++;
		}
		i++;
	}
}

void	scale(float f, t_map *map)
{
	int				i;
	int				u;
	static float	fp = 1;

	i = 0;
	if (f == 0)
	{
		fp = 1;
		return ;
	}
	if (fp >= MAX_ZOOM && f > 1)
		return ;
	fp *= f;
	while (i < map->max.y)
	{
		u = 0;
		while (u < map->max.x)
		{
			map->map[i][u].x *= f;
			map->map[i][u].y *= f;
			map->map[i][u].z *= f;
			u++;
		}
		i++;
	}
}
