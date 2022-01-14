/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:15:01 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/14 02:23:59 by nthimoni         ###   ########.fr       */
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
#include "colors.h"

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
	t_2point p1 = {W_WIDTH / 2, W_HEIGHT / 2};
	for (int i = 0; i < W_WIDTH; i += 20)
	{	
		pix_put_img(i, 0, RED, &img);
		pix_put_img(i, W_HEIGHT - 1, RED, &img);

		draw_line(p1, (t_2point){i, 0}, &img);
		draw_line(p1, (t_2point){i, W_HEIGHT - 1}, &img);

	}
	for (int i = 0; i < W_HEIGHT; i += 20)
	{	
		pix_put_img(0, i, RED, &img);
		pix_put_img(W_WIDTH - 1, i, RED, &img);
		draw_line(p1, (t_2point){0, i}, &img);
		draw_line(p1, (t_2point){W_WIDTH - 1, i}, &img);


	}
		draw_line(p1, (t_2point){p1.x, p1.y + 50}, &img);
		draw_line(p1, (t_2point){p1.x, p1.y - 50}, &img);
		draw_line(p1, (t_2point){p1.x + 50, p1.y}, &img);
		draw_line(p1, (t_2point){p1.x - 50, p1.y}, &img);
		draw_line(p1, (t_2point){p1.x + 50, p1.y + 50}, &img);
		draw_line(p1, (t_2point){p1.x - 50, p1.y - 50}, &img);
		draw_line(p1, (t_2point){p1.x + 50, p1.y - 50}, &img);
		draw_line(p1, (t_2point){p1.x - 50, p1.y + 50}, &img);
		pix_put_img(p1.x, p1.y + 50, RED, &img);
		pix_put_img(p1.x, p1.y - 50, RED, &img);
		pix_put_img(p1.x + 50, p1.y, RED, &img);
		pix_put_img(p1.x - 50, p1.y, RED, &img);
		pix_put_img(p1.x + 50, p1.y + 50, RED, &img);
		pix_put_img(p1.x - 50, p1.y - 50, RED, &img);
		pix_put_img(p1.x + 50, p1.y - 50, RED, &img);
		pix_put_img(p1.x - 50, p1.y + 50, RED, &img);
	pix_put_img(p1.x, p1.y, RED, &img);
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
