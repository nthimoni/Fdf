/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 02:34:43 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 16:06:22 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	mkcolor(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int color)
{
	return (((unsigned char *)&color)[3]);
}

unsigned char	get_r(int color)
{
	return (((unsigned char *)&color)[2]);
}

unsigned char	get_g(int color)
{
	return (((unsigned char *)&color)[1]);
}

unsigned char	get_b(int color)
{
	return (((unsigned char *)&color)[0]);
}
