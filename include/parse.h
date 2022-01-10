/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 05:28:19 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/10 07:02:40 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct	s_point
{
	int x;
	int y;
	int z;
} t_point;

typedef struct	s_map
{
	t_point	**map;
	t_point	max;
} t_map;

#endif
