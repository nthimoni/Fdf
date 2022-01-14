/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:03:19 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/14 07:46:13 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->max.y)
		free(map->map[i++]);
	free(map->map);
}

int	quit(t_prog *prog)
{
	mlx_loop_end(prog->win.mlx);
	return (0);
}
