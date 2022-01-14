/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:14:04 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/14 09:10:02 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFO_H
# define TRANSFO_H

# include "fdf.h"

void	translate(int tx, int ty, int tz, t_map *map);
void	rotateX(float tx, t_map *map);
void	rotateY(float tx, t_map *map);
void	rotateZ(float tx, t_map *map);
void	scale(float sx, float sy, float sz, t_map *map);
void	extrude(float ex);

#endif
