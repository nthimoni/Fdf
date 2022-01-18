/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 01:47:39 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/18 02:41:27 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "constantes.h"
#include "colors.h"
#include "libft.h"

static	int	ft_atoi_base(char *line, char *base)
{
	int		ret;
	int		i;
	size_t	len;

	len = ft_strlen(base);
	i = 0;
	ret = 0;
	while (line[i] && ft_strchr(base, line[i]))
	{
		ret *= len;
		ret += ft_strchr(base, line[i]) - base;
		i++;
	}
	return (ret);
}

void	fill_point(t_point *pnt, char *line, int i, int u)
{
	int	j;

	pnt->x = (float)(i * X_SC);
	pnt->y = (float)(u * Y_SC);
	pnt->z = (float)(ft_atoi(line) * Z_SC);
	j = 0;
	while (line[j])
	{
		if (line[j] == 'x')
		{
			pnt->color = ft_atoi_base(line + j + 1, "0123456789ABCDEF");
			return ;
		}
		j++;
	}
	if (pnt->z <= GROUND_MAX)
		pnt->color = GROUND_C;
	else if (pnt->z / Z_SC <= LVL_1_MAX)
		pnt->color = LVL_1_C;
	else
		pnt->color = LVL_2_C;
}
