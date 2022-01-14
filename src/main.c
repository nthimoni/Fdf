/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:15:01 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/14 05:56:33 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"
#include "fdf.h"
#include "libft.h"
#include "parse.h"
#include "constantes.h"
#include "mlx.h"
#include "error.h"
#include "quit.h"
#include "hook.h"
#include "draw_line.h"
#include "draw.h"
#include "colors.h"
#include "transfo.h"

static int	init(t_win *win, t_map *map, int argc, char *argv[])
{
	int	error_code;

	win->mlx = mlx_init();
	if (!win->mlx)
		return (error_msg(BAD_ALLOC));
	win->win = mlx_new_window(win->mlx, W_WIDTH, W_HEIGHT, W_TITLE);
	if (!win->win)
		return (error_msg(BAD_ALLOC));
	win->w = W_WIDTH;
	win->h = W_HEIGHT;
	map->map = NULL;
	map->max = (t_point){0, 0, 0};
	if (argc != 2)
		return (error_msg(INV_ARG));
	error_code = parse_map(map, argv[1]);
	return (error_msg(error_code));
}

int	main(int argc, char *argv[])
{
	t_prog	prog;
	t_img	img;

	if (!init(&prog.win, &prog.map, argc, argv))
		return (-1);
	new_img(&img, &prog.win);
	rotateY(-(M_PI / 4), &prog.map);
	rotateX(M_PI / 4, &prog.map);
	rotateZ(M_PI / 4, &prog.map);
	translate(300, 300 , 0, &prog.map);
	print_map_img(&prog.map, &img);
	mlx_put_image_to_window(prog.win.mlx, prog.win.win, img.img, 0, 0);
	mlx_hook(prog.win.win, KeyPress, KeyPressMask, key_pressed_hook, &prog);
	mlx_hook(prog.win.win, DestroyNotify, StructureNotifyMask, quit, &prog);
	mlx_loop(prog.win.mlx);
	mlx_destroy_image(prog.win.mlx, img.img);
	mlx_destroy_window(prog.win.mlx, prog.win.win);
	mlx_destroy_display(prog.win.mlx);
	free(prog.win.mlx);
	return (0);
}
