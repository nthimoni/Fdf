/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 01:47:39 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/19 15:54:35 by nthimoni         ###   ########.fr       */
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

static int	get_hex_color(int *color, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'x')
		{
			*color = ft_atoi_base(line + i + 1, HEXA_B);
			return (1);
		}
		i++;
	}
	return (0);
}

void	fill_point(t_map *map, char *line, int i, int u)
{
	int		j;
	float	z;

	map->map[u][i].x = (float)(i * X_SC);
	map->map[u][i].y = (float)(u * Y_SC);
	map->map[u][i].z = (float)(ft_atoi(line) * Z_SC);
	z = map->map[u][i].z / Z_SC;
	j = 0;
	if (get_hex_color(&map->map[u][i].color, line))
		return ;
	if (z <= GROUND_H)
		map->map[u][i].color = GROUND_C;
	else if (z <= LVL_2_H)
	{
		map->map[u][i].color = mix_color(LVL_1_C, LVL_2_C,
				1 - (z - GROUND_H) / (LVL_2_H - GROUND_H));
	}
	else
	{
		map->map[u][i].color = mix_color(LVL_3_C, LVL_4_C,
				1 - (z - LVL_2_H) / (map->max.z - LVL_2_H));
	}
}
