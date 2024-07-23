/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_shape_and_size.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:59:26 by achak             #+#    #+#             */
/*   Updated: 2024/03/14 14:59:00 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_width(char *map_width)
{
	int	count;

	count = 0;
	while (*map_width++)
		count++;
	return (count);
}

int	count_map_height(char **map_arr)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (map_arr[i++])
		count++;
	return (count);
}

int	check_map_dimensions(char **map_arr)
{
	int	width1;
	int	width2;
	int	height;

	width1 = -1;
	width2 = -1;
	height = -1;
	while (map_arr[++height])
	{
		width2 = width1;
		width1 = ft_strlen(map_arr[height]);
		if (width1 < MIN_WIDTH)
			print_error("Map is too small\n", map_arr);
		if (width2 != -1 && width1 != width2)
			return (MLX_ERROR);
	}
	if (height < MIN_HEIGHT)
		print_error("Map is too small\n", map_arr);
	return (0);
}

void	check_map_shape_and_size(char **map_arr)
{
	if (check_map_dimensions(map_arr))
		print_error("Map is not rectangular\n", map_arr);
	if ((count_map_width(map_arr[0]) >= MIN_WIDTH
			&& count_map_height(map_arr) >= MIN_HEIGHT + 2)
		|| (count_map_width(map_arr[0]) >= MIN_WIDTH + 2
			&& count_map_height(map_arr) >= MIN_HEIGHT))
		return ;
	else
		print_error("Map is too small\n", map_arr);
}
