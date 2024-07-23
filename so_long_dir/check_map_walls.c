/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:17:02 by achak             #+#    #+#             */
/*   Updated: 2024/03/11 18:34:17 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_width(char **map_arr, int index)
{
	int	i;

	i = -1;
	while (++i < count_map_width(*map_arr))
		if (map_arr[index][i] != '1')
			print_error("Map not surrounded by walls\n", map_arr);
}

void	check_map_height(char **map_arr, int index)
{
	int	i;

	i = -1;
	while (++i < count_map_height(map_arr))
		if (map_arr[i][index] != '1')
			print_error("Map not surrounded by walls\n", map_arr);
}

void	check_map_walls(char **map_arr)
{
	check_map_width(map_arr, 0);
	check_map_width(map_arr, count_map_height(map_arr) - 1);
	check_map_height(map_arr, 0);
	check_map_height(map_arr, count_map_width(*map_arr) - 1);
}
