/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_components.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:54:25 by achak             #+#    #+#             */
/*   Updated: 2024/03/13 17:39:29 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall(t_data *data, int j, int i, int colour)
{
	int	wall_width;
	int	wall_height;
	int	k;
	int	l;

	wall_width = GRID_WIDTH * j;
	wall_height = GRID_HEIGHT * i;
	k = -1;
	while (++k < GRID_HEIGHT)
	{
		l = -1;
		while (++l < GRID_WIDTH)
			img_pixel_put(&data->img[0], wall_width + l,
				wall_height + k, colour);
	}
}

void	render_block(t_data *data, int j, int i, int colour)
{
	int		block_width;
	int		block_height;
	int		index;
	float	k;
	float	l;

	block_width = GRID_WIDTH * j;
	block_height = GRID_HEIGHT * i;
	index = 0;
	k = GRID_HEIGHT / 4;
	while (k < (GRID_HEIGHT * 0.75))
	{
		l = GRID_WIDTH / 4;
		while (l < (GRID_WIDTH * 0.75))
			img_pixel_put(&data->img[index], block_width + l++,
				block_height + k, colour);
		k++;
	}
}

/*
//	if (colour == RED_PIXEL)
//		index = 2;
//	else
void	render_circle(t_data *data, int j, int i, int colour)
{
	float	radius;
	float	centre_x;
	float	centre_y;
	int	k;
	int	l;

	radius = GRID_WIDTH * 0.4;
	centre_x = (GRID_WIDTH * 0.5) + (GRID_WIDTH * j);
	centre_y = (GRID_HEIGHT * 0.5) + (GRID_HEIGHT * i);
	k = -1;
	while (++k < (radius * 2))
	{
		l = -1;
		while (++l < (radius * 2))
			img_pixel_put(data, j + centre_x, i + centre_y, colour);
	}
}
*/

void	render_map_component(t_data *data, char c, int colour)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			if (data->map.map_arr[i][j] == c)
			{
				if (c == '1' || c == '0')
					render_wall(data, j, i, colour);
				else
					render_block(data, j, i, colour);
			}
		}
	}
}
/*
//			else if (data->map.map_arr[i][j] == 'C')
//				render_block(data, j, i, YELLOW_PIXEL);
//			else if (data->map.map_arr[i][j] == 'P')
//				render_block(data, j, i, RED_PIXEL);
//			else if (data->map.map_arr[i][j] == 'E')
//				render_block(data, j, i, BLUE_PIXEL);
//			else
//				continue ;
*/
