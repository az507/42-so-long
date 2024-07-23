/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:44:30 by achak             #+#    #+#             */
/*   Updated: 2024/03/12 14:25:06 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_s1_to_s2(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
}

char	**copy_map(char **map_arr)
{
	char	**map_cpy;
	int		i;

	i = -1;
	map_cpy = (char **)malloc(sizeof(char *) * (count_map_height(map_arr) + 1));
	if (map_cpy)
	{
		map_cpy[count_map_height(map_arr)] = NULL;
		while (++i < count_map_height(map_arr))
		{
			map_cpy[i] = (char *)malloc(sizeof(char)
					* (count_map_width(*map_arr) + 1));
			if (!map_cpy[i])
			{
				free_arr(map_cpy);
				break ;
			}
			map_cpy[i][count_map_width(*map_arr)] = '\0';
			copy_s1_to_s2(map_arr[i], map_cpy[i]);
		}
	}
	return (map_cpy);
}

int	*find_position_of_component(char **map_arr, char component)
{
	int	i;
	int	j;
	int	*pos;

	i = -1;
	pos = (int *)malloc(sizeof(int) * 2);
	if (pos)
	{
		while (map_arr[++i])
		{
			j = -1;
			while (map_arr[i][++j])
			{
				if (map_arr[i][j] == component)
				{
					pos[0] = i;
					pos[1] = j;
					return (pos);
				}
			}
		}
	}
	return (pos);
}

void	check_valid_path(char **map_arr, t_map *map)
{
	char	**map_cpy;
	int		*sp;

	map_cpy = copy_map(map_arr);
	sp = find_position_of_component(map_arr, 'P');
	flood_fill(map_cpy, sp, 'F');
	if (!check_if_filled(map_cpy, 'C', 'E'))
	{
		free(sp);
		print_error("Map does not have a valid path\n", map_arr);
	}
	map->sp = sp;
	free_arr(map_cpy);
}
/*
	i = -1;
	while (map_cpy[++i])
	printf("map_cpy[i] = %s\n", map_cpy[i]);
*/
