/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:15:01 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/11 05:36:52 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;
	int		u;

	map.map = NULL;
	map.max = (t_point){0, 0, 0};
	if (argc != 2)
		ft_printf("Error : Invalid argument\n");
	if (!parse_map(&map, argv[1]))
		ft_printf("Error : Invalid argument\n");
	i = 0;
	while (i < map.max.y)
	{
		u = 0;
		while (u < map.max.x)
		{
			ft_printf("%3d", map.map[i][u].z);
			u++;
		}
		ft_printf("\n");
		i++;
	}
}
