/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:18:35 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/12 19:18:37 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit.h"
#include "fdf.h"
#include "keys.h"

int	key_pressed_hook(int keycode, t_prog *prog)
{
	if (keycode == ESC_K)
		quit(prog);
	return (0);
}
