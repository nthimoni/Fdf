/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:37:04 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 21:10:28 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "img.h"
#include "draw_line.h"
#include "colors.h"
#include "constantes.h"

void	print_tab(t_prog *prog)
{
	int	i;
	int	u;

	i = 0;
	while (i < prog->map.max.y)
	{
		u = 0;
		while (u < prog->map.max.x)
		{
			ft_printf("%3d ", (int)prog->map.map[i][u].z);
			u++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_map_img(t_map *map, t_img *img)
{
	int	u;
	int	i;

	i = 0;
	while (i < map->max.y)
	{
		u = 0;
		while (u < map->max.x)
		{
			if (u != map->max.x - 1)
				draw_line((t_2point){(int)map->map[i][u].x,
					(int)map->map[i][u].y},
					(t_2point){(int)map->map[i][u + 1].x,
					(int)map->map[i][u + 1].y}, img,
					mix_color(map->map[i][u].color,
					map->map[i][u + 1].color, 0.5));
			if (i != map->max.y - 1)
				draw_line((t_2point){(int)map->map[i][u].x,
					(int)map->map[i][u].y},
					(t_2point){(int)map->map[i + 1][u].x,
					(int)map->map[i + 1][u].y}, img,
					mix_color(map->map[i + 1][u].color,
					map->map[i][u].color, 0.5));
			u++;
		}
		i++;
	}
}

int	render(t_prog *prog)
{
	t_img	*tmp;

	tmp = prog->img;
	prog->img = prog->buf;
	prog->buf = tmp;
	ft_bzero(prog->img->addr, sizeof(int) * W_WIDTH * W_HEIGHT);
	print_map_img(&prog->map, prog->img);
	mlx_put_image_to_window(prog->win.mlx, prog->win.win, prog->img->img, 0, 0);
	return (0);
}
