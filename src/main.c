/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:15:01 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/12 06:43:42 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "constantes.h"
#include "mlx.h"
#include "error.h"
#include "quit.h"
#include "hook.h"

static int error_msg(int code)
{
	if (code == 0)
		return (1);
	if (code == INV_ARG)
		ft_printf("Invalid argument !\n");
	else if (code == BAD_ALLOC)
		ft_printf("Erreur lors de l'allocation de la memoire !\n");
	else if (code == MAP_FORMAT)
		ft_printf("Le format du fichier map n'est pas standard !\n");
	return (0);
}

static int	init(t_win *win, t_map *map, int argc, char *argv[])
{
	int	error_code;
	win->mlx = mlx_init();
	if (!win->mlx)
		return (error_msg(BAD_ALLOC));
	win->win = mlx_new_window(win->mlx, W_WIDTH, W_HEIGHT, W_TITLE);
	if (!win->win)
		return (error_msg(BAD_ALLOC));
	map->map = NULL;
	map->max = (t_point){0, 0, 0};
	if (argc != 2)
		return (error_msg(INV_ARG));
	error_code = parse_map(map, argv[1]);
	return (error_msg(error_code));
}

int	main(int argc, char *argv[])
{
	t_prog prog;
	int		i;
	int		u;

	if (!init(&prog.win, &prog.map, argc, argv))
		return (0);
	i = 0;
	while (i < prog.map.max.y)
	{
		u = 0;
		while (u < prog.map.max.x)
		{
			ft_printf("%3d ", prog.map.map[i][u].z);
			u++;
		}
		ft_printf("\n");
		i++;
	}
	mlx_hook(prog.win.win, 2, (1L<<0), key_pressed_hook, &prog);
    mlx_loop(prog.win.mlx);
	free(prog.win.mlx);
    return (0);
}
