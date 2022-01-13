/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 22:37:04 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/13 00:15:27 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	print_tab(t_prog *prog)
{
	int	i;
	int	u;

	i = 0;
	while (i < prog->map.max.y)
	{
		u = 0;
		while (u < prog->map.max.x)
		{
			ft_printf("%3d ", (int)prog->map.map[i][u].z);
			u++;
		}
		ft_printf("\n");
		i++;
	}
}
