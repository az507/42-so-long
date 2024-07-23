/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:25:50 by achak             #+#    #+#             */
/*   Updated: 2024/03/12 13:14:36 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_components(char **map_arr)
{
	int	i;
	int	j;

	i = -1;
	while (map_arr[++i])
	{
		j = -1;
		while (map_arr[i][++j])
		{
			if (map_arr[i][j] != '1' && map_arr[i][j] != '0' &&
				map_arr[i][j] != 'C' && map_arr[i][j] != 'E'
				&& map_arr[i][j] != 'P')
				print_error("Unrecognized map component\n",
					map_arr);
		}
	}
}

void	check_if_special_component(char component, int *exit, int *collectible,
		int *start)
{
	if (component == 'E')
		*exit += 1;
	else if (component == 'C')
		*collectible += 1;
	else if (component == 'P')
		*start += 1;
}

void	check_no_of_special_components(char **map_arr, t_map *map)
{
	int	exit;
	int	start;
	int	i;
	int	j;

	exit = 0;
	start = 0;
	i = -1;
	while (map_arr[++i])
	{
		j = -1;
		while (map_arr[i][++j])
			check_if_special_component(map_arr[i][j], &exit,
				&map->collectible, &start);
	}
	if (exit == 1 && map->collectible >= 1 && start == 1)
		return ;
	print_error("Invalid number of special components\n", map_arr);
}
