/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:07:50 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/12 06:06:22 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	t_point	**map;
	t_point	max;
}	t_map;

typedef struct s_win
{
	void			*mlx;
	void			*win;
}	t_win;

typedef struct s_prog
{
	t_map			map;
	t_win			win;
}	t_prog;
#endif
