/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:18:35 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/17 22:22:33 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit.h"
#include "fdf.h"
#include "keys.h"
#include "constantes.h"
#include "transfo.h"
#include "libft.h"
#include "draw.h"

static void	transfo(int keycode, t_prog *prog)
{
	if (keycode == S_K)
		translate(0, CAM_SPEED, 0, &prog->map);
	else if (keycode == D_K)
		translate(CAM_SPEED, 0, 0, &prog->map);
	else if (keycode == W_K)
		translate(0, -CAM_SPEED, 0, &prog->map);
	else if (keycode == A_K)
		translate(-CAM_SPEED, 0, 0, &prog->map);
	else if (keycode == J_K)
		rotate_x(M_PI / ROT_DIV, &prog->map);
	else if (keycode == K_K)
		rotate_y(M_PI / ROT_DIV, &prog->map);
	else if (keycode == L_K)
		rotate_z(M_PI / ROT_DIV, &prog->map);
	else if (keycode == PLUS_K)
		scale(1 + SCALE_SPEED, &prog->map);
	else if (keycode == MINUS_K)
		scale(1 - SCALE_SPEED, &prog->map);
	else if (keycode == T_K)
		isoview(&prog->map);
	else if (keycode == Y_K)
		paraview(&prog->map);
}

int	key_pressed_hook(int keycode, t_prog *prog)
{
	if (keycode == ESC_K)
		quit(prog);
	else
		transfo(keycode, prog);
	render(prog);
	return (0);
}
