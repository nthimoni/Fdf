/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:18:35 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/14 09:21:29 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit.h"
#include "fdf.h"
#include "keys.h"
#include "constantes.h"
#include "transfo.h"
#include "libft.h"
#include "draw.h"

int	key_pressed_hook(int keycode, t_prog *prog)
{
	if (keycode == ESC_K)
		quit(prog);
	else if (keycode == S_K)
		translate(0, CAM_SPEED, 0, &prog->map);
	else if (keycode == D_K)
		translate(CAM_SPEED, 0, 0, &prog->map);
	else if (keycode == W_K)
		translate(0, -CAM_SPEED, 0, &prog->map);
	else if (keycode == A_K)
		translate(-CAM_SPEED, 0, 0, &prog->map);
	else if (keycode == J_K)
		rotateX(ROT_SPEED, &prog->map);
	else if (keycode == K_K)
		rotateY(ROT_SPEED, &prog->map);
	else if (keycode == L_K)
		rotateZ(ROT_SPEED, &prog->map);
	else if (keycode == PLUS_K)
		scale(1 + SCALE_SPEED, 1 + SCALE_SPEED, 1 + SCALE_SPEED, &prog->map);
	else if (keycode == MINUS_K)
		scale(1 - SCALE_SPEED, 1 - SCALE_SPEED, 1 - SCALE_SPEED, &prog->map);
	else
		ft_printf("%d\n", keycode);
	render(prog);
	return (0);
}
