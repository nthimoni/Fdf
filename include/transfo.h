/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:14:04 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/17 18:56:39 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFO_H
# define TRANSFO_H

# include "fdf.h"

void	translate(int tx, int ty, int tz, t_map *map);
void	rotate_x(float tx, t_map *map);
void	rotate_y(float tx, t_map *map);
void	rotate_z(float tx, t_map *map);
void	scale(float f, t_map *map);
void	paraview(t_map *map);
void	isoview(t_map *map);

#endif
