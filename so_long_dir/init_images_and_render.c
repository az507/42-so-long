/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_and_render.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:27:11 by achak             #+#    #+#             */
/*   Updated: 2024/03/14 14:30:18 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_pixel_put(t_img *img, int x, int y, int colour)
{
	char	*dest;

	dest = img->addr + (y * img->size_line) + (x * (img->bpp / 8));
	*(int *)dest = colour;
}

void	render_background(t_data *data, int index, int colour)
{
	int	i;
	int	j;

	if (!data->win_ptr)
		return ;
	i = -1;
	while (++i < data->window_height)
	{
		j = -1;
		while (++j < data->window_width)
			img_pixel_put(&data->img[index], j, i, colour);
	}
}

int	find_map_component(t_data *data, char component)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
			if (data->map.map_arr[i][j] == component)
				return (1);
	}
	return (0);
}

int	render(t_data *data)
{
	static int	flag = 0;

	render_map_component(data, '0', BLACK_PIXEL);
	render_map_component(data, '1', WHITE_PIXEL);
	render_map_component(data, 'C', YELLOW_PIXEL);
	render_map_component(data, 'E', BLUE_PIXEL);
	if (flag == 1)
		exit_success(data);
	if (data->map.collectible == 0 && !find_map_component(data, 'E'))
		flag = 1;
	render_map_component(data, 'P', RED_PIXEL);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[0].img_ptr, 0, 0);
	return (0);
}

void	init_img_ptr(t_data *data, int index, float width, float height)
{
	data->img[index].img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	if (!data->img[index].img_ptr)
		return ;
	data->img[index].addr = mlx_get_data_addr(data->img[index].img_ptr,
			&data->img[index].bpp, &data->img[index].size_line,
			&data->img[index].endian);
}

/*
void	prepare_images(t_data *data)
{
	init_img_ptr(data, 0, data->window_width, data->window_height);
}
//
	//render_background(data, 0, WHITE_PIXEL);
//	render_map_component(data, 'P', RED_PIXEL);
//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
//		data->img[2].img_ptr, data->map.sp[0] * GRID_WIDTH,
//		data->map.sp[1] * GRID_HEIGHT);
//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
//		data->img[1].img_ptr, 0, 0);
//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
//		data->img[2].img_ptr, 0, 0);
//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1].img_ptr,
//			0, 0);
//
//	init_img_ptr(data, 1, data->window_width, data->window_height);
//	init_img_ptr(data, 2, 0.5 * GRID_WIDTH, 0.5 * GRID_HEIGHT);
//	if (data->map.collectible == 0)
//		render_map_component(data, 'P', RED_PIXEL);
//		render_map_component(data, 'E', BLUE_PIXEL);
*/
