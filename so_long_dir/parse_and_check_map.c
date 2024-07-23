/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_check_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:53:38 by achak             #+#    #+#             */
/*   Updated: 2024/03/13 17:10:56 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_and_assign_map(char **map_arr, t_map *map)
{
	map->collectible = 0;
	check_map_shape_and_size(map_arr);
	check_map_components(map_arr);
	check_no_of_special_components(map_arr, map);
	check_map_walls(map_arr);
	check_valid_path(map_arr, map);
	map->width = count_map_width(*map_arr);
	map->height = count_map_height(map_arr);
	map->exit_pos0 = -1;
	map->exit_pos1 = -1;
	return (map_arr);
}

char	**parse_map(char *file, t_map *map)
{
	char	**map_arr;
	char	*map_buffer;
	char	*next_line;
	int		fd;

	map_buffer = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("File can't be opened or doesn't exist\n", NULL);
	next_line = get_next_line(fd);
	if (!next_line)
		print_error("File is empty\n", NULL);
	while (next_line)
	{
		map_buffer = strjoin_and_frees1(map_buffer, next_line);
		free(next_line);
		next_line = get_next_line(fd);
	}
	close(fd);
	map_arr = ft_split(map_buffer, '\n');
	free(map_buffer);
	return (check_and_assign_map(map_arr, map));
}
