/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:18:35 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/12 06:33:28 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quit.h"
#include "fdf.h"

int	key_pressed_hook(int keycode, t_prog *prog)
{
	if (keycode == 65307)
		quit(prog);
	return (0);
}
