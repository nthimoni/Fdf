/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:03:19 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/12 07:01:08 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

static void free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->max.y)
		free(map->map[i++]);
	free(map->map);
}

int quit(t_prog *prog)
{
	free_map(&prog->map);
	mlx_loop_end(prog->win.mlx);
	mlx_destroy_window(prog->win.mlx, prog->win.win);
	//mlx_destroy_display(prog->win.mlx);
	return (0);
}
