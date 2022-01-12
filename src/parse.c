/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 06:14:48 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/12 07:09:14 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "error.h"

static int	get_map_size(t_map *map, char *file)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (INV_ARG);
	line = get_next_line(fd);
	if (!line)
		return (MAP_FORMAT);
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' && (i == 0 || line[i - 1] != ' '))
			map->max.x++;
		i++;
	}
	map->max.x++;
	while (line)
	{
		free(line);
		map->max.y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int	free_part_map(t_map *map, int i)
{
	while (--i >= 0)
		free(map->map[i]);
	free(map->map);
	return (BAD_ALLOC);
}	

static int	map_alloc(t_map *map)
{
	int	i;

	map->map = malloc(sizeof(t_point *) * map->max.y);
	if (!map->map)
		return (BAD_ALLOC);
	i = 0;
	while (i < map->max.y)
	{
		map->map[i] = malloc(sizeof(t_point) * map->max.x);
		if (!map->map[i])
			return (free_part_map(map, i));
		i++;
	}
	return (0);
}

static void	fill_map(t_map *map, char *file)
{
	int		fd;
	char	*line;
	char	**words;
	int		i;
	int		u;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	u = 0;
	while (line)
	{
		i = 0;
		words = ft_split(line, ' ');
		while (words[i])
		{
			map->map[u][i].x = i;
			map->map[u][i].y = u;
			map->map[u][i].z = ft_atoi(words[i]);
			free(words[i]);
			i++;
		}
		free(words);
		free(line);
		line = get_next_line(fd);
		u++;
	}
	close(fd);
}

int	parse_map(t_map *map, char *file)
{
	int	error;

	error = get_map_size(map, file);
	if (error)
		return (error);
	error = map_alloc(map);
	if (error)
		return (error);
	fill_map(map, file);
	return (0);
}
