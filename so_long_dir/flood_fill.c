/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:19:40 by achak             #+#    #+#             */
/*   Updated: 2024/03/12 11:58:15 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map_arr, int x, int y, char to_fill)
{
	if (map_arr[x][y] == '1' || map_arr[x][y] == to_fill)
		return ;
	map_arr[x][y] = to_fill;
	fill(map_arr, x + 1, y, to_fill);
	fill(map_arr, x - 1, y, to_fill);
	fill(map_arr, x, y + 1, to_fill);
	fill(map_arr, x, y - 1, to_fill);
}

void	flood_fill(char **map_cpy, int *sp, char to_fill)
{
	fill(map_cpy, sp[0], sp[1], to_fill);
}

int	check_if_filled(char **map_cpy, char special1, char special2)
{
	int	i;
	int	j;

	i = -1;
	while (map_cpy[++i])
	{
		j = -1;
		while (map_cpy[i][++j])
		{
			if (map_cpy[i][j] == special1 || map_cpy[i][j]
				== special2)
			{
				free_arr(map_cpy);
				return (0);
			}
		}
	}
	return (1);
}
