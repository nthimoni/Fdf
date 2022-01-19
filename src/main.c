/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:15:01 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/19 16:07:54 by nthimoni         ###   ########.fr       */
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

	if (argc != 2)
		return (error_msg(INV_ARG));
	map->map = NULL;
	map->path = argv[1];
	map->max = (t_point){0, 0, 0, STD_COLOR};
	error_code = isoview(map);
	if (error_code)
		return (error_msg(error_code));
	win->mlx = mlx_init();
	if (!win->mlx)
		return (error_msg(BAD_ALLOC));
	win->win = mlx_new_window(win->mlx, W_WIDTH, W_HEIGHT, W_TITLE);
	if (!win->win)
		return (error_msg(BAD_ALLOC));
	win->w = W_WIDTH;
	win->h = W_HEIGHT;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_prog	prog;
	t_img	img;
	t_img	img2;

	if (!init(&prog.win, &prog.map, argc, argv))
		return (-1);
	new_img(&img, &prog.win);
	new_img(&img2, &prog.win);
	prog.img = &img;
	prog.buf = &img2;
	print_map_img(&prog.map, prog.img);
	render(&prog);
	mlx_hook(prog.win.win, KeyPress, KeyPressMask, key_pressed_hook, &prog);
	mlx_hook(prog.win.win, DestroyNotify, StructureNotifyMask, quit, &prog);
	mlx_loop(prog.win.mlx);
	free_map(&prog.map);
	mlx_destroy_image(prog.win.mlx, img.img);
	mlx_destroy_image(prog.win.mlx, img2.img);
	mlx_destroy_window(prog.win.mlx, prog.win.win);
	mlx_destroy_display(prog.win.mlx);
	free(prog.win.mlx);
	return (0);
}
