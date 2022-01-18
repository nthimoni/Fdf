/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 01:47:39 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 23:39:39 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "constantes.h"
#include "colors.h"
#include "libft.h"

static	int	ft_atoi_base(char *line, char *base)
{
	int		ret;
	int		i;
	size_t	len;

	len = ft_strlen(base);
	i = 0;
	ret = 0;
	while (line[i] && ft_strchr(base, line[i]))
	{
		ret *= len;
		ret += ft_strchr(base, line[i]) - base;
		i++;
	}
	return (ret);
}
#include <stdio.h>
void	fill_point(t_map *map, char *line, int i, int u)
{
	int		j;
	float	z;

	map->map[u][i].x = (float)(i * X_SC);
	map->map[u][i].y = (float)(u * Y_SC);
	map->map[u][i].z = (float)(ft_atoi(line) * Z_SC);
	z = map->map[u][i].z / Z_SC;
	j = 0;
	while (line[j])
	{
		if (line[j] == 'x')
		{
			map->map[u][i].color = ft_atoi_base(line + j + 1, HEXA_B);
			return ;
		}
		j++;
	}
	if (z <= GROUND_H)
		map->map[u][i].color = GROUND_C;
	else if (z <= LVL_2_H)
	{
		map->map[u][i].color = mix_color(LVL_1_C, LVL_2_C,
		1 - (z - GROUND_H)/(LVL_2_H - GROUND_H));
	}
	else
	{
		map->map[u][i].color = mix_color(LVL_3_C, LVL_4_C,
		1 - (z - LVL_2_H)/(map->max.z - LVL_2_H));
	}
}
