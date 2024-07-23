/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:12:46 by achak             #+#    #+#             */
/*   Updated: 2024/03/13 17:38:32 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_map map)
{
	t_data	data;

	data.map = map;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return ;
	data.window_width = map.width * GRID_WIDTH;
	data.window_height = map.height * GRID_HEIGHT;
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.window_width,
			data.window_height, "So long");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return ;
	}
	init_img_ptr(&data, 0, data.window_width, data.window_height);
	set_up_hooks(&data);
}
